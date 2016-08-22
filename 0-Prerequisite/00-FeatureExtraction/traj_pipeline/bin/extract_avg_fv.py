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
spbof_bin = "./bin/spbof"
traj_bin = "./bin/DenseTrackStab"
fv_bin = "./bin/fisher"
fv_option = " 1 2 0.5 "
fv_codebook = "./codebook_pca_list"
file = open(argv[0], 'r')

fps_path = "/data/MM2/MED/resized_videos/MED13_resized.all"
segx_path = "/data/MM22/iyu/semantic_concepts/feats/MED9746segx/"

fps = dict()
with open(fps_path, 'r') as f:
    for line in f:
        name = ((line.split()[0]).split('/')[-1]).split('.')[0]
        width = line.split()[1]
        height = line.split()[2]
        fps_num = line.split()[3]
        fps[name] = [width, height, fps_num]
        

cd = "cd " + os.getcwd()



for line in file:
    src_path = line[:-1]
    src_name = os.path.basename(src_path)
    original_name = src_name.split('.')[0]
    txyc_name = original_name + ".txyc"
    bof_name = original_name + ".bof"
    spbof_name = original_name + ".spbof"
    record_name = original_name + ".txyc.bof.record"
    fv_name = original_name + ".fv"

    avg_fv_cmd = "./bin/avg_fisher.py " + src_path + " ./fv_avg/" + src_name + " 872448" 
    avg_record_cmd = "touch ./fv_avg_record/" + original_name + ".record"


    #print "(" + cd + " && " + traj_cmd + " | " + fv_cmd + " > /dev/null && " + record_cmd + ") 1>/dev/null 2>/dev/null"
    #print "(" + cd + " && " + spbof_traj + " && " + spbof_hog + " && " + spbof_hof + " && " + spbof_mbhx + " && " + spbof_mbhy + " && " + record_cmd + ") 1>/dev/null 2>/dev/null"
    print "(" + cd + " && " + avg_fv_cmd + " && " + avg_record_cmd + ") 1>/dev/null 2>/dev/null"
