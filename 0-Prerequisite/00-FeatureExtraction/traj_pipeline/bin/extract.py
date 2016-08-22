#!/usr/bin/env python

import os.path
import sys

argv = sys.argv[1:]

#input_path = "/data/MM21/xuanchong/traj_pyr/fusion_5_10_15/raw_list"
#input_path = "/data/MM21/xuanchong/traj_pyr/dense15/mbh/txyc_list"

output_path = "./"
centers_file = "./raw_1m.cluster_centres"
index_file = "./raw_1m.index"

traj_option = " 1,2,0 10-39 "
hog_option = " 1,2,0 40-135 "
hof_option = " 1,2,0 136-243 "
mbhx_option = " 1,2,0 244-339 "
mbhy_option = " 1,2,0 340-435 "

traj_path = "./traj/"
hog_path = "./hog/"
hof_path = "./hof/"
mbhx_path = "./mbhx/"
mbhy_path = "./mbhy/"

centers_file = "raw_1m.cluster_centres"
index_file = "raw_1m.index"

#traj_bin = "../../bin/DenseTrackStab"
lib_cmd = "export LD_LIBRARY_PATH=/data/MM21/xuanchong/Code/lib:$LD_LIBRARY_PATH"
txyc_bin = "./bin/txyc_pipe"
bof_bin = "./bin/bof"
traj_bin = "./bin/DenseTrackStab"
file = open(argv[0], 'r')


cd = "cd " + os.getcwd()


for line in file:
    src_path = line[:-1]
    src_name = os.path.basename(src_path)
    original_name = src_name.split('.')[0]
    txyc_name = original_name + ".txyc"
    bof_name = original_name + ".bof"
    record_name = original_name + ".txyc.bof.record"
    txyc_traj = txyc_bin + " " + traj_path + centers_file + " 4096 " + traj_path + index_file + " " + traj_path + "txyc/" + txyc_name + traj_option
    bof_traj = bof_bin + " " + traj_path + "txyc/" + txyc_name + " 4096 10 " + traj_path + "bof/" + bof_name
    txyc_hog = txyc_bin + " " + hog_path + centers_file + " 4096 " + hog_path + index_file + " " + hog_path + "txyc/" + txyc_name + hog_option
    bof_hog = bof_bin + " " + hog_path + "txyc/" + txyc_name + " 4096 10 " + hog_path + "bof/" + bof_name
    txyc_hof = txyc_bin + " " + hof_path + centers_file + " 4096 " + hof_path + index_file + " " + hof_path + "txyc/" + txyc_name + hof_option
    bof_hof = bof_bin + " " + hof_path + "txyc/" + txyc_name + " 4096 10 " + hof_path + "bof/" + bof_name
    txyc_mbhx = txyc_bin + " " + mbhx_path + centers_file + " 4096 " + mbhx_path + index_file + " " + mbhx_path + "txyc/" + txyc_name + mbhx_option
    bof_mbhx = bof_bin + " " + mbhx_path + "txyc/" + txyc_name + " 4096 10 " + mbhx_path + "bof/" + bof_name
    txyc_mbhy = txyc_bin + " " + mbhy_path + centers_file + " 4096 " + mbhy_path + index_file + " " + mbhy_path + "txyc/" + txyc_name + mbhy_option
    bof_mbhy = bof_bin + " " + mbhy_path + "txyc/" + txyc_name + " 4096 10 " + mbhy_path + "bof/" + bof_name
    record_cmd = "touch ./record/" + record_name
    traj_cmd = traj_bin + " " + src_path

    print "(" + cd + " && " + traj_cmd + " | " + txyc_traj + " | " + txyc_hog + " | " + txyc_hof + " | " + txyc_mbhx + " | " + txyc_mbhy + " > /dev/null && " + bof_traj + " && " + bof_hog + " && " + bof_hof + " && " + bof_mbhx + " && " + bof_mbhy + " && " + record_cmd + ") 1>/dev/null 2>/dev/null"

