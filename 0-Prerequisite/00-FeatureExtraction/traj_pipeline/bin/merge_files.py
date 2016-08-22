#!/usr/bin/env python2.7
import random
import gzip

#feature_file_path = "/data/MM21/xuanchong/traj_pyr/dense15/raw_list"

def main(argv):
    file_list_path = argv[0]
    with open(file_list_path) as f:
        for line in f: 
            with open(line.rstrip('\n')) as ff:
                for line in ff:
                    print line.rstrip('\n')

import sys
if __name__ == "__main__":
    if len(sys.argv) == 2: 
        main(sys.argv[1:])
    else:
        print("Usage: merge_files.py file_list")
