#!/usr/bin/env python2.7
import os
import sys

def main( argv ):
    if len(argv) != 3:
        print "Usage: multi_class.py result_dir num_labels num_data"
        sys.exit(1)

    result_dir = argv[0]
    num_labels = int(argv[1])
    num_data = int(argv[2])

    combined_p = [float(0) for i in range(num_data)]
    combined_l = [float(0) for i in range(num_data)]
    for label in range(1, num_labels + 1): 
        result_file = open(result_dir + "/" + str(label) + "_output", "r")

        result_contents = result_file.readlines()

        label_pos = 0
        if int(result_contents[0].split()[1]) == 1:
            label_pos = 1
        else:
            label_pos = 2

        for id, label_str in zip(range(len(result_contents)-1),result_contents[1:]): 
            p=float(label_str.split()[label_pos])

            if p > combined_p[id]:
                combined_p[id] = p
                combined_l[id] = label
           
        result_file.close()

    for l in combined_l:
        print l

if __name__ == '__main__':
    main(sys.argv[1:])

