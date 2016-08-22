#!/usr/bin/env python

import os.path
import sys

argv = sys.argv[1:]

#input_path = "/data/MM21/xuanchong/traj_pyr/fusion_5_10_15/raw_list"
#input_path = "/data/MM21/xuanchong/traj_pyr/dense15/mbh/txyc_list"
output_path = "./"
centers_file = "./raw_100k.cluster_centres"
index_file = "./raw_1m.index"
txyc_option = " 1,2,0 40-435 "
#traj_bin = "../../bin/DenseTrackStab"
lib_cmd = "export LD_LIBRARY_PATH=/data/MM21/xuanchong/Code/lib:$LD_LIBRARY_PATH"
txyc_bin = "../../bin/txyc_caiyang"
bof_bin = "../../bin/bof"
file = open(argv[0], 'r')

for line in file:
    src_path = line[:-1]
    src_name = os.path.basename(src_path)
    #output = "( " + lib_cmd + " && " + traj_bin + " " + src_path + " > " + output_path + "raw/" + src_name + ".traj " + " && touch " + output_path + "record/" + src_name + ".record " + " )>/dev/null 2>/dev/null"
    output = "( " + txyc_bin + " " + centers_file + " 4096 " + index + " " + src_path + " " + output_path + "txyc/" + txyc_name + txyc_option + " && " + bof_bin + " " + output_path + "txyc/" + txyc_name + " 4096 10 " + output_path + "bof/" + bof_name + " 0" + " && touch " + output_path + "record/" + src_name + ".bof.record " + ")>/dev/null 2>/dev/null"
    #output = "( " + bof_bin + " " + src_path + " 4000 10 " + output_path + "bof/" + src_name + ".bof 0" + " && touch " + output_path + "record/" + src_name + ".bof.record " + ")>/dev/null 2>/dev/null"

    print output

