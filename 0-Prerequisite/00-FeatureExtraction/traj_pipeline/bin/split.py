#!/usr/bin/env python

import os.path
import sys
import os

argv = sys.argv[1:]

output_path = "./"
split_bin = "./bin/split_len.py"
split_arg = "20,40,60"
file = open(argv[0], 'r')
cd = "cd " + os.getcwd()

for line in file:
    src_path = line[:-1]
    src_name = os.path.basename(src_path)
    output = cd + " && " + split_bin + " " + src_path + " " + split_arg
    print output

