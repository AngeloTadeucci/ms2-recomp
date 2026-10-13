// Export a binary map for offline classification. Args: <outdir>
//   functions.tsv : entry  size  thunk(0/1)  namespace::name
//   vtables.tsv   : vtable-addr  namespace  slot-index  target-entry       (from RTTI-labelled ``vftable`` symbols)
//   strrefs.tsv   : function-entry  string-addr  string (escaped, first 200 chars)
//   calls.tsv     : caller-entry  callee-entry
//@category MS2

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.StringDataInstance;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;

import java.io.File;
import java.io.PrintWriter;

public class ExportMap extends GhidraScript {
    private static String esc(String s) {
        if (s.length() > 200) s = s.substring(0, 200);
        return s.replace("\\", "\\\\").replace("\t", "\\t").replace("\n", "\\n").replace("\r", "\\r");
    }

    @Override
    protected void run() throws Exception {
        File out = new File(getScriptArgs()[0]);
        out.mkdirs();
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();
        ReferenceManager rm = currentProgram.getReferenceManager();
        Memory mem = currentProgram.getMemory();
        long ptrSize = currentProgram.getDefaultPointerSize();

        try (PrintWriter wf = new PrintWriter(new File(out, "functions.tsv"));
             PrintWriter ws = new PrintWriter(new File(out, "strrefs.tsv"));
             PrintWriter wc = new PrintWriter(new File(out, "calls.tsv"))) {
            int n = 0;
            for (Function f : fm.getFunctions(true)) {
                if (monitor.isCancelled()) break;
                wf.printf("%s\t%d\t%d\t%s%n", f.getEntryPoint(), f.getBody().getNumAddresses(), f.isThunk() ? 1 : 0,
                          f.getName(true));
                for (Function callee : f.getCalledFunctions(monitor))
                    wc.printf("%s\t%s%n", f.getEntryPoint(), callee.getEntryPoint());
                for (Instruction ins : listing.getInstructions(f.getBody(), true)) {
                    for (Reference r : ins.getReferencesFrom()) {
                        if (!r.getReferenceType().isData()) continue;
                        Data d = listing.getDataAt(r.getToAddress());
                        if (d == null || !d.hasStringValue()) continue;
                        String sv = StringDataInstance.getStringDataInstance(d).getStringValue();
                        if (sv == null) continue;
                        ws.printf("%s\t%s\t%s%n", f.getEntryPoint(), r.getToAddress(), esc(sv));
                    }
                }
                if (++n % 20000 == 0) println("functions: " + n);
            }
        }

        try (PrintWriter wv = new PrintWriter(new File(out, "vtables.tsv"))) {
            SymbolIterator it = currentProgram.getSymbolTable().getSymbols("vftable");
            int n = 0;
            while (it.hasNext()) {
                Symbol s = it.next();
                Address a = s.getAddress();
                String ns = s.getParentNamespace().getName(true);
                for (int i = 0; i < 4096; i++) {
                    Address slot = a.add(i * ptrSize);
                    if (i > 0 && currentProgram.getSymbolTable().getPrimarySymbol(slot) != null
                            && rm.getReferencesTo(slot).hasNext()) break;   // next labelled object starts
                    long v;
                    try { v = mem.getLong(slot); } catch (Exception e) { break; }
                    Address t = a.getNewAddress(v);
                    Function f = fm.getFunctionAt(t);
                    if (f == null) {
                        if (!mem.contains(t) || !mem.getBlock(t).isExecute()) break;
                    }
                    wv.printf("%s\t%s\t%d\t%s%n", a, ns, i, t);
                }
                n++;
            }
            println("vtables: " + n);
        }
    }
}
