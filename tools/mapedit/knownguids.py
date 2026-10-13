#!/usr/bin/env python3
"""Build known_guids.json: real model GUIDs that can be recovered for MS2's library models.

Sources (all read-only):
  * MS2 Library.m2d   *.diagram  -> EntityModelID list of the real model GUIDs of that library
                      *.preset   -> Mixin SourceID/SourceName = real GUID of the base model
  * Gamebryo SDK Media/*ModelLibrary/*.model  (name -> ID): MS2's standard/physx models are the SDK ones, accepted only
    when the SDK GUID occurs in an MS2 diagram (so it is certain that MS2 uses that GUID for that model).
Every other model/preset gets a deterministic uuid5 (flatrecon.model_guid).

  knownguids.py [--library work/maps/extracted/Library] [--sdk third_party/gamebryo/APPDIR] [-o tools/mapedit/known_guids.json]
"""
import argparse, glob, json, os, re

HERE = os.path.dirname(os.path.abspath(__file__))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--library', default='work/maps/extracted/Library')
    ap.add_argument('--sdk', default='third_party/gamebryo/APPDIR')
    ap.add_argument('-o', default=os.path.join(HERE, 'known_guids.json'))
    a = ap.parse_args()
    diagram_ids = set()
    for f in glob.glob(os.path.join(a.library, '*', '*.diagram')):
        diagram_ids.update(re.findall(r'EntityModelID="([0-9a-f-]{36})"', open(f, encoding='utf-8-sig').read()))
    known = {}
    src = {}
    for f in glob.glob(os.path.join(a.library, '*', '*.preset')):
        t = open(f, encoding='utf-8-sig').read()
        m = re.search(r'SourceID="([^"]+)"\s+SourceName="([^"]+)"', t)
        if m:
            known[m.group(2)] = m.group(1)
            src[m.group(2)] = 'ms2-preset-mixin'
    sdk_names = {}
    for f in glob.glob(os.path.join(a.sdk, 'Media', '*ModelLibrary', '*.model')):
        t = open(f, encoding='utf-8-sig').read(3000)
        m = re.search(r'\bID="([^"]+)"', t)
        sdk_names[os.path.basename(f)[:-6]] = m.group(1)
    for n, g in sdk_names.items():
        if g in diagram_ids and n not in known:
            known[n] = g
            src[n] = 'sdk-guid-confirmed-by-ms2-diagram'
    matched = set(known.values())
    out = dict(_comment='Real GUIDs recovered for MS2 library models; everything else is uuid5(NAMESPACE_URL, "ms2-model:"+name).',
               models=dict(sorted(known.items())), sources={k: src[k] for k in sorted(src)},
               diagram_guids_total=len(diagram_ids), diagram_guids_unmatched=sorted(diagram_ids - matched))
    json.dump(out, open(a.o, 'w'), indent=1)
    print('known guids:', len(known), 'of', len(diagram_ids), 'diagram GUIDs; unmatched', len(diagram_ids - matched))


if __name__ == '__main__':
    main()
