#!/usr/bin/env python3
"""Export Toolbench WorldBuilder .block files to runtime .xblock (re-implementation of XmlBlockExporter).

  block2xblock.py in.block... -o outdir [--index flatindex.json] [--dialect tab|toolbench] [--sort-properties]
"""
import argparse, os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from msmap.models import ModelIndex
from msmap.convert import block_to_xblocks
from msmap.block import read_block


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('input', nargs='+')
    ap.add_argument('-o', '--outdir', required=True)
    ap.add_argument('--index')
    ap.add_argument('--dialect', default='tab', choices=['tab', 'toolbench'])
    ap.add_argument('--sort-properties', action='store_true', help='sort properties by name (default: keep block order)')
    a = ap.parse_args(argv)
    index = ModelIndex(a.index)
    os.makedirs(a.outdir, exist_ok=True)
    for f in a.input:
        blk = read_block(f)
        for w in block_to_xblocks(blk, index, os.path.dirname(os.path.abspath(f)), a.outdir, a.dialect, a.sort_properties):
            print(w)


if __name__ == '__main__':
    main()
