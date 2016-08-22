#!/usr/bin/env python2.7
import random
import gzip
import sets
import os

#feature_file_path = "/data/MM21/xuanchong/traj_pyr/dense15/raw_list"

def main(argv):
    original_list_path = argv[0]
    record_list_path = argv[1]
    with open(original_list_path, 'r') as f:
        with open(record_list_path, 'r') as ff:
            dict = sets.Set([os.path.basename(l.rstrip('\n')).split('.')[0] for l in ff.readlines()])
            for line in f:
                name = os.path.basename(line.rstrip('\n')).split('.')[0]
                if name not in dict:
                    print line.rstrip('\n')

import sys
if __name__ == "__main__":
    if len(sys.argv) == 3: 
        main(sys.argv[1:])
    else:
        print("Usage: check.py original_list record_list")
