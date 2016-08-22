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
sp_fv_option = " 1 2 0.5 "
nosp_fv_option = " 0 2 0.5 "
fv_codebook = "./codebook_pca_list"
fv_xyt_codebook = "/data/MM21/iyu/semantic_concepts/gmm_MED_xyt/codebook_pca_list"
fv_xy_codebook = "/data/MM21/iyu/semantic_concepts/gmm_MED_xy/codebook_pca_list"
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
        

cd = "set -o pipefail && cd " + os.getcwd()


for line in file:
    src_path = line[:-1]
    src_name = os.path.basename(src_path)
    original_name = src_name.split('.')[0]
    txyc_name = original_name + ".txyc"
    bof_name = original_name + ".bof"
    spbof_name = original_name + ".spbof"
    record_name = original_name + ".record"
    fv_name = original_name + ".fv"

    width = fps[original_name][0]
    height = fps[original_name][1]
    fps_num = fps[original_name][2]

    size = " " + width + " " + height + " "

    txyc_traj = txyc_bin + " " + traj_path + centers_file + " 4096 " + traj_path + index_file + " " + traj_path + "txyc/" + txyc_name + traj_option
    bof_traj = bof_bin + " " + traj_path + "txyc/" + txyc_name + " 4096 10 " + traj_path + "bof/" + bof_name
    spbof_traj = spbof_bin + " " + traj_path + "txyc/" + txyc_name + size + "4096 10 " + traj_path + "spbof/" + spbof_name + " 1"
    txyc_hog = txyc_bin + " " + hog_path + centers_file + " 4096 " + hog_path + index_file + " " + hog_path + "txyc/" + txyc_name + hog_option
    bof_hog = bof_bin + " " + hog_path + "txyc/" + txyc_name + " 4096 10 " + hog_path + "bof/" + bof_name
    spbof_hog = spbof_bin + " " + hog_path + "txyc/" + txyc_name + size +  "4096 10 " + hog_path + "spbof/" + spbof_name + " 1"
    txyc_hof = txyc_bin + " " + hof_path + centers_file + " 4096 " + hof_path + index_file + " " + hof_path + "txyc/" + txyc_name + hof_option
    bof_hof = bof_bin + " " + hof_path + "txyc/" + txyc_name + " 4096 10 " + hof_path + "bof/" + bof_name
    spbof_hof = spbof_bin + " " + hof_path + "txyc/" + txyc_name + size + "4096 10 " + hof_path + "spbof/" + spbof_name + " 1"
    txyc_mbhx = txyc_bin + " " + mbhx_path + centers_file + " 4096 " + mbhx_path + index_file + " " + mbhx_path + "txyc/" + txyc_name + mbhx_option
    bof_mbhx = bof_bin + " " + mbhx_path + "txyc/" + txyc_name + " 4096 10 " + mbhx_path + "bof/" + bof_name
    spbof_mbhx = spbof_bin + " " + mbhx_path + "txyc/" + txyc_name + size + "4096 10 " + mbhx_path + "spbof/" + spbof_name + " 1"
    txyc_mbhy = txyc_bin + " " + mbhy_path + centers_file + " 4096 " + mbhy_path + index_file + " " + mbhy_path + "txyc/" + txyc_name + mbhy_option
    bof_mbhy = bof_bin + " " + mbhy_path + "txyc/" + txyc_name + " 4096 10 " + mbhy_path + "bof/" + bof_name
    spbof_mbhy = spbof_bin + " " + mbhy_path + "txyc/" + txyc_name + size + "4096 10 " + mbhy_path + "spbof/" + spbof_name + " 1"
    record_cmd = "touch ./record/" + record_name
    traj_cmd = traj_bin + " " + src_path
    segx = segx_path + original_name + ".segx"

    fv_cmd = fv_bin + " ./fv/" + fv_name + size + segx + " " + fps_num + sp_fv_option + "0 " + fv_codebook
    fv_sp_vid_cmd = fv_bin + " ./fv_sp_vid/" + fv_name + size + segx + " " + "-1" + sp_fv_option + "0 " + fv_codebook
    fv_nosp_vid_cmd = fv_bin + " ./fv_nosp_vid/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "0 " + fv_codebook
    fv_nosp_shot_cmd = fv_bin + " ./fv_nosp_shot/" + fv_name + size + segx + " " + fps_num + nosp_fv_option + "0 " + fv_codebook

    fv_xyt_nosp_vid_cmd = fv_bin + " ./fv_xyt_nosp_vid/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "3 " + fv_xyt_codebook
    fv_xy_nosp_vid_cmd = fv_bin + " ./fv_xy_nosp_vid/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "2 " + fv_xy_codebook

    fv_xyt_sp_vid_cmd = fv_bin + " ./fv_xyt_sp_vid/" + fv_name + size + segx + " " + "-1" + sp_fv_option + "3 " + fv_xyt_codebook
    fv_xy_sp_vid_cmd = fv_bin + " ./fv_xy_sp_vid/" + fv_name + size + segx + " " + "-1" + sp_fv_option + "2 " + fv_xy_codebook


    #print "(" + cd + " && " + traj_cmd + " | " + fv_cmd + " > /dev/null && " + record_cmd + ") 1>/dev/null 2>/dev/null"
    #print "(" + cd + " && " + spbof_traj + " && " + spbof_hog + " && " + spbof_hof + " && " + spbof_mbhx + " && " + spbof_mbhy + " && " + record_cmd + ") 1>/dev/null 2>/dev/null"
    #print "(" + cd + " && " + traj_cmd + " | " + txyc_traj + " | " + txyc_hog + " | " + txyc_hof + " | " + txyc_mbhx + " | " + txyc_mbhy +  " | " + fv_cmd + " > /dev/null && " + spbof_traj + " && " + spbof_hog + " && " + spbof_hof + " && " + spbof_mbhx + " && " + spbof_mbhy + " && " + record_cmd + ") 1>/dev/null 2>/dev/null"
    print "(" + cd + " && " + traj_cmd + " | " + fv_sp_vid_cmd + " | " + fv_nosp_vid_cmd + " | " + fv_nosp_shot_cmd + " | " + fv_xyt_nosp_vid_cmd + " | " + fv_xy_nosp_vid_cmd + " | " + fv_xy_sp_vid_cmd + " | " + fv_xyt_sp_vid_cmd + " > /dev/null " + "&& " + record_cmd + ") 1>/dev/null 2>/dev/null"

