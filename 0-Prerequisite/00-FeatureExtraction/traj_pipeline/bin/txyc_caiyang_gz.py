#!/usr/bin/env python2.7
import os
import sys

def main( argv ):
    if len(argv) != 7:
        print "Usage: txyc_caiyang_gz.py txyc_caiyang center_file k feature_file.gz txyc_file param_idx_1,param_idx_i,...,param_idx_n:( e.g. 6,3,7 means dim 6,3,7 are kept and will be output in the order of 6, 3, 7 Note: index starting from 0!) feature_index_range( e.g.5-132, index starting from 0!)"
        sys.exit(1)

    gz_path = argv[3] 
    txt_path = gz_path+".txt"

    new_argv = argv
    new_argv[3] = txt_path

    os.system("gunzip -c " + gz_path + " > " + txt_path)
    os.system(' '.join(new_argv))
    os.system("rm " + txt_path)

if __name__ == '__main__':
    main(sys.argv[1:])

