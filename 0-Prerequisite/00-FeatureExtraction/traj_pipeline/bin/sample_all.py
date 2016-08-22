#!/usr/bin/env python

import os.path
import sys

argv = sys.argv[1:]

#input_path = "/data/MM21/xuanchong/traj_pyr/fusion_5_10_15/raw_list"
#input_path = "/data/MM21/xuanchong/traj_pyr/dense15/mbh/txyc_list"
output_path = "./"
#centers_file = "/data/MM21/xuanchong/traj_pyr/fusion_5_10_15/txt_100k_all.cluster_centres"
#txyc_option = " 1,2,0 10-405 "
#traj_bin = "./bin/DenseTrackStab"
sample_bin = "./bin/sample_gz.py"
sample_ratio = '0.001'
#bb_path = "/data/MM22/lanzhzh/data/HMDB51/boundingbox/bb/"
#txyc_bin = "./bin/txyc_caiyang"
#bof_bin = "./bin/bof"
file = open(argv[0], 'r')

for line in file:
    src_path = line[:-1]
    src_name = os.path.basename(src_path)
    first_name = src_name.split('.')[0]
    output = "( " + sample_bin + " " + sample_ratio + " " +  src_path + " > ./sampled/" + first_name + ".sampled " + " )>/dev/null 2>/dev/null"
    #output = "( " + txyc_bin + " " + centers_file + " 4000 " + src_path + " " + output_path + "txyc/" + src_name + ".txyc" + txyc_option + " && touch " + output_path + "record/" + src_name + ".txyc.record " + ")>/dev/null 2>/dev/null"
    # output = "( " + bof_bin + " " + src_path + " 4000 10 " + output_path + "bof/" + src_name + ".bof 0" + " && touch " + output_path + "record/" + src_name + ".bof.record " + ")>/dev/null 2>/dev/null"
    print output

