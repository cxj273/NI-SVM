#!/usr/bin/env python2.7
import os
import sys
import gzip

def main( argv ):
    if len(argv) != 3:
        print "Usage: avg_fisher.py src_fv des_fv dim"
        sys.exit(1)

    src_path = argv[0]
    dest_path = argv[1]
    dim = int(argv[2])

    src_file = gzip.open(src_path,'r')
    dest_file = gzip.open(dest_path,'w')

    
    avg_feat = [0.0]*(dim+1)
    norm = 0
    for line in src_file:
        for item in line.split():
            idx = int(item.split(":")[0])
            value = float(item.split(":")[1])
            avg_feat[idx] += value
        norm += 1

    assert norm > 0
    for i in range(1,dim + 1):
        dest_file.write(str(i) + ":" + str(avg_feat[i]/norm))
        if i != dim:
            dest_file.write(" ")
        else:
            dest_file.write("\n")


    src_file.close()
    dest_file.close()



if __name__ == '__main__':
    main(sys.argv[1:])

