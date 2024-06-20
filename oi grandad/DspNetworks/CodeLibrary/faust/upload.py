#!/usr/bin/env python3

import argparse
import os
import shutil
import subprocess

parser = argparse.ArgumentParser('Upload Faust samples')
parser.add_argument('--owl', help='path to OwlProgram directory', default='../../OwlProgram/')
parser.add_argument('--slot', help='slot number used for first patch', default=1, type=int)

args = parser.parse_args()

faust_files = [fname for fname in os.listdir() if fname.endswith('.dsp')]
faust_files.sort()

cwd = os.path.abspath('.')
owl = os.path.abspath(args.owl)

env = os.environ.copy()

print(f'Using owl program from {owl}')

for i, fname in enumerate(faust_files):
    # copy file without first 2 symbols used for sorting
    dst = os.path.join(owl, 'PatchSource', fname[2:])
    shutil.copy(fname, dst)
    # set env vars for current patch processing
    env['SLOT'] = str(args.slot + i)
    env['FAUST'] = fname[2:-4]
    print()
    print(f'{env["SLOT"]} <= {env["FAUST"]}')
    # upload patch
    subprocess.run(['make', 'clean', 'store'], cwd=os.path.abspath(args.owl), env=env)
    os.remove(dst)
