#!/usr/bin/env python2.7
import random

#feature_file_path = "/data/MM21/xuanchong/traj_pyr/dense15/raw_list"

def main(argv):
    sample_ratio = float(argv[0])
    feature_file_path = argv[1]
    with open(feature_file_path) as f:
        for line in f:
            path = line.rstrip("\n")
            with open(path) as ff:
                for line in ff:
                    if random.random() < sample_ratio:
                        print line.rstrip("\n")

import sys
if __name__ == "__main__":
    if len(sys.argv) == 3: 
        main(sys.argv[1:])
    else:
        print("Usage: sample.py <sample_ratio> <list_file>")
