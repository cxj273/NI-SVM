#!/usr/bin/env python

import os.path
import time
import sys

RAMDISK = True

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
ramdisk_path = "$SCRATCH_RAMDISK/"
time_stamp = str(time.time())

centers_file = "raw_1m.cluster_centres"
index_file = "raw_1m.index"

#traj_bin = "../../bin/DenseTrackStab"
lib_cmd = "export LD_LIBRARY_PATH=/data/MM21/xuanchong/Code/lib:$LD_LIBRARY_PATH"
txyc_bin = "./bin/txyc_pipe"
bof_bin = "./bin/bof"
spbof_bin = "./bin/spbof"
traj_bin = "./bin/DenseTrackStab"
homo_map_bin = "./bin/homo_map_pipe"
traj_skip2_bin = "./bin/DenseTrackStab_skip2"
traj_skip3_bin = "./bin/DenseTrackStab_skip3"
traj_skip4_bin = "./bin/DenseTrackStab_skip4"
traj_skip5_bin = "./bin/DenseTrackStab_skip5"
traj_skip6_bin = "./bin/DenseTrackStab_skip6"

fv_bin = "./bin/fisher"
sp_fv_option = " 1 2 0.5 "
nosp_fv_option = " 0 2 0.5 "
fv_codebook = "./codebook_pca_list"
fv_xyt_codebook = "/data/MM21/iyu/semantic_concepts/gmm_MED_xyt/codebook_pca_list"
fv_xy_codebook = "/data/MM21/iyu/semantic_concepts/gmm_MED_xy/codebook_pca_list"
file = open(argv[0], 'r')

fps_path = "/home/ubuntu/Code/traj_pipeline/MED14_resized.all"
segx_path = "/brashear/iyu2/xcli/MEDTEST14/segx/"

sfv_4_bin = "./bin/sfv_4"
sfv_8_bin = "./bin/sfv_8"
sfv_16_bin = "./bin/sfv_16"

fv_128_codebook = "./gmm_combo/gmm_MED_128/codebook_pca_list"
fv_512_codebook = "./gmm_combo/gmm_MED_512/codebook_pca_list"
fv_1024_codebook = "./gmm_combo/gmm_MED_1024/codebook_pca_list"

fv_xy_128_codebook = "./gmm_combo/gmm_MED_xy_128/codebook_pca_list"
fv_xy_256_codebook = "./gmm_combo/gmm_MED_xy_256/codebook_pca_list"
fv_xy_512_codebook = "./gmm_combo/gmm_MED_xy_512/codebook_pca_list"
fv_xy_1024_codebook = "./gmm_combo/gmm_MED_xy_1024/codebook_pca_list"

fv_xyt_128_codebook = "./gmm_combo/gmm_MED_xyt_128/codebook_pca_list"
fv_xyt_256_codebook = "./gmm_combo/gmm_MED_xyt_256/codebook_pca_list"
fv_xyt_512_codebook = "./gmm_combo/gmm_MED_xyt_512/codebook_pca_list"
fv_xyt_1024_codebook = "./gmm_combo/gmm_MED_xyt_1024/codebook_pca_list"

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
    fv_name = original_name

    width = fps[original_name][0]
    height = fps[original_name][1]
    fps_num = fps[original_name][2]

    size = " " + width + " " + height + " "
	
    if RAMDISK:
        txyc_traj_path = ramdisk_path + time_stamp + "_traj_" + txyc_name;
        txyc_hog_path = ramdisk_path + time_stamp + "_hog_" + txyc_name;
        txyc_hof_path = ramdisk_path + time_stamp + "_hof_" + txyc_name;
        txyc_mbhx_path = ramdisk_path + time_stamp + "_mbhx_" + txyc_name;
        txyc_mbhy_path = ramdisk_path + time_stamp + "_mbhy_" + txyc_name;
    else:
        txyc_traj_path = "./traj/txyc/" + txyc_name;
        txyc_hog_path = "./hog/txyc/" + txyc_name;
        txyc_hof_path = "./hof/txyc/" + txyc_name;
        txyc_mbhx_path = "./mbhx/txyc/" + txyc_name;
        txyc_mbhy_path = "./mbhy/txyc/" + txyc_name;

    txyc_traj = txyc_bin + " " + traj_path + centers_file + " 4096 " + traj_path + index_file + " " + txyc_traj_path + traj_option
    clean_txyc_traj = "rm " + txyc_traj_path
    bof_traj = bof_bin + " " + txyc_traj_path + " 4096 10 " + traj_path + "bof/" + bof_name
    spbof_traj = spbof_bin + " " + txyc_traj_path + size + "4096 10 " + traj_path + "spbof/" + spbof_name + " 1"
    spbof_map_traj = "cat " + traj_path + "spbof/" + spbof_name + " | " + homo_map_bin + " 1 0.5 > " + traj_path + "spbof_mapped/" + spbof_name

    txyc_hog = txyc_bin + " " + hog_path + centers_file + " 4096 " + hog_path + index_file + " " + txyc_hog_path + hog_option
    clean_txyc_hog = "rm " + txyc_hog_path
    bof_hog = bof_bin + " " + txyc_hog_path + " 4096 10 " + hog_path + "bof/" + bof_name
    spbof_hog = spbof_bin + " " + txyc_hog_path + size +  "4096 10 " + hog_path + "spbof/" + spbof_name + " 1"
    spbof_map_hog = "cat " + hog_path + "spbof/" + spbof_name + " | " + homo_map_bin + " 1 0.5 > " + hog_path + "spbof_mapped/" + spbof_name

    txyc_hof = txyc_bin + " " + hof_path + centers_file + " 4096 " + hof_path + index_file + " " + txyc_hof_path + hof_option
    clean_txyc_hof = "rm " + txyc_hof_path
    bof_hof = bof_bin + " " + txyc_hof_path + " 4096 10 " + hof_path + "bof/" + bof_name
    spbof_hof = spbof_bin + " " + txyc_hof_path + size + "4096 10 " + hof_path + "spbof/" + spbof_name + " 1"
    spbof_map_hof = "cat " + hof_path + "spbof/" + spbof_name + " | " + homo_map_bin + " 1 0.5 > " + hof_path + "spbof_mapped/" + spbof_name

    txyc_mbhx = txyc_bin + " " + mbhx_path + centers_file + " 4096 " + mbhx_path + index_file + " " + txyc_mbhx_path + mbhx_option
    clean_txyc_mbhx = "rm " + txyc_mbhx_path
    bof_mbhx = bof_bin + " " + txyc_mbhx_path + " 4096 10 " + mbhx_path + "bof/" + bof_name
    spbof_mbhx = spbof_bin + " " + txyc_mbhx_path + size + "4096 10 " + mbhx_path + "spbof/" + spbof_name + " 1"
    spbof_map_mbhx = "cat " + mbhx_path + "spbof/" + spbof_name + " | " + homo_map_bin + " 1 0.5 > " + mbhx_path + "spbof_mapped/" + spbof_name

    txyc_mbhy = txyc_bin + " " + mbhy_path + centers_file + " 4096 " + mbhy_path + index_file + " " + txyc_mbhy_path + mbhy_option
    clean_txyc_mbhy = "rm " + txyc_mbhy_path
    bof_mbhy = bof_bin + " " + txyc_mbhy_path + " 4096 10 " + mbhy_path + "bof/" + bof_name
    spbof_mbhy = spbof_bin + " " + txyc_mbhy_path + size + "4096 10 " + mbhy_path + "spbof/" + spbof_name + " 1"
    spbof_map_mbhy = "cat " + mbhy_path + "spbof/" + spbof_name + " | " + homo_map_bin + " 1 0.5 > " + mbhy_path + "spbof_mapped/" + spbof_name

    txyc_cmd = txyc_traj + " | " + txyc_hog + " | " + txyc_hof + " | " + txyc_mbhx + " | " + txyc_mbhy
    txyc_clean_cmd = clean_txyc_traj + " && " + clean_txyc_hog + " && " + clean_txyc_hof + " && " + clean_txyc_mbhx + " && " + clean_txyc_mbhy
    spbof_cmd = spbof_traj + " && " + spbof_hog + " && " + spbof_hof + " && " + spbof_mbhx + " && " + spbof_mbhy
    spbof_map_cmd = spbof_map_traj + " && " + spbof_map_hog + " && " + spbof_map_hof + " && " + spbof_map_mbhx + " && " + spbof_map_mbhy

    record_cmd = "touch ./record/" + record_name
    traj_cmd = traj_bin + " " + src_path
    traj_skip2_cmd = traj_skip2_bin + " " + src_path
    traj_skip3_cmd = traj_skip3_bin + " " + src_path
    traj_skip4_cmd = traj_skip4_bin + " " + src_path
    traj_skip5_cmd = traj_skip5_bin + " " + src_path
    traj_skip6_cmd = traj_skip6_bin + " " + src_path
    segx = segx_path + original_name + ".segx"

    fv_cmd = fv_bin + " ./fv/" + fv_name + size + segx + " " + fps_num + sp_fv_option + "0 " + fv_codebook
    fv_sp_vid_cmd = fv_bin + " ./fv_sp_vid/" + fv_name + size + segx + " " + "-1" + sp_fv_option + "0 " + fv_codebook
    fv_nosp_vid_cmd = fv_bin + " ./fv_nosp_vid/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "0 " + fv_codebook
    fv_nosp_shot_cmd = fv_bin + " ./fv_nosp_shot/" + fv_name + size + segx + " " + fps_num + nosp_fv_option + "0 " + fv_codebook

    fv_xyt_nosp_vid_cmd = fv_bin + " ./fv_xyt_nosp_vid/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "3 " + fv_xyt_codebook
    fv_xy_nosp_vid_cmd = fv_bin + " ./fv_xy_nosp_vid/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "2 " + fv_xy_codebook

    fv_xyt_sp_vid_cmd = fv_bin + " ./fv_xyt_sp_vid/" + fv_name + size + segx + " " + "-1" + sp_fv_option + "3 " + fv_xyt_codebook
    fv_xy_sp_vid_cmd = fv_bin + " ./fv_xy_sp_vid/" + fv_name + size + segx + " " + "-1" + sp_fv_option + "2 " + fv_xy_codebook

    fv_128_nosp_cmd = fv_bin + " ./fv_128_nosp/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "0 " + fv_128_codebook
    fv_128_sp_cmd = fv_bin + " ./fv_128_sp/" + fv_name + size + segx + " " + "-1" + sp_fv_option + "0 " + fv_128_codebook
    fv_512_nosp_cmd = fv_bin + " ./fv_512_nosp/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "0 " + fv_512_codebook
    fv_1024_nosp_cmd = fv_bin + " ./fv_1024_nosp/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "0 " + fv_1024_codebook

    fv_xy_128_nosp_cmd = fv_bin + " ./fv_128_xy_nosp/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "2 " + fv_xy_128_codebook
    fv_xy_128_sp_cmd = fv_bin + " ./fv_128_xy_sp/" + fv_name + size + segx + " " + "-1" + sp_fv_option + "2 " + fv_xy_128_codebook
    fv_xy_256_nosp_cmd = fv_bin + " ./fv_256_xy_nosp/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "2 " + fv_xy_256_codebook
    fv_xy_256_sp_cmd = fv_bin + " ./fv_256_xy_sp/" + fv_name + size + segx + " " + "-1" + sp_fv_option + "2 " + fv_xy_256_codebook
    fv_xy_512_nosp_cmd = fv_bin + " ./fv_512_xy_nosp/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "2 " + fv_xy_512_codebook
    fv_xy_1024_nosp_cmd = fv_bin + " ./fv_1024_xy_nosp/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "2 " + fv_xy_1024_codebook

    fv_xyt_128_nosp_cmd = fv_bin + " ./fv_128_xyt_nosp/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "3 " + fv_xyt_128_codebook
    fv_xyt_128_sp_cmd = fv_bin + " ./fv_128_xyt_sp/" + fv_name + size + segx + " " + "-1" + sp_fv_option + "3 " + fv_xyt_128_codebook
    fv_xyt_256_nosp_cmd = fv_bin + " ./fv_256_xyt_nosp/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "3 " + fv_xyt_256_codebook
    fv_xyt_256_sp_cmd = fv_bin + " ./fv_256_xyt_sp/" + fv_name + size + segx + " " + "-1" + sp_fv_option + "3 " + fv_xyt_256_codebook
    fv_xyt_512_nosp_cmd = fv_bin + " ./fv_512_xyt_nosp/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "3 " + fv_xyt_512_codebook
    fv_xyt_1024_nosp_cmd = fv_bin + " ./fv_1024_xyt_nosp/" + fv_name + size + segx + " " + "-1" + nosp_fv_option + "3 " + fv_xyt_1024_codebook

    sfv_4_cmd = sfv_4_bin + " ./sfv_4/" + fv_name
    sfv_8_cmd = sfv_8_bin + " ./sfv_8/" + fv_name
    sfv_16_cmd = sfv_16_bin + " ./sfv_16/" + fv_name
    
    ensemble_fv_cmd = "./bin/extract_fv ./fv_nosp_noskip_vid/" + fv_name + " ./fv_nosp_vid/" + fv_name + " ./fv_nosp_noskip_shot/" + fv_name + " " + segx + " " + fps_num + " " + fv_codebook

    #print "(" + cd + " && " + traj_cmd + " | " + fv_cmd + " > /dev/null && " + record_cmd + ") 1>/dev/null 2>/dev/null"
    #print "(" + cd + " && " + spbof_traj + " && " + spbof_hog + " && " + spbof_hof + " && " + spbof_mbhx + " && " + spbof_mbhy + " && " + record_cmd + ") 1>/dev/null 2>/dev/null"
    #print "(" + cd + " && " + traj_cmd + " | " + txyc_traj + " | " + txyc_hog + " | " + txyc_hof + " | " + txyc_mbhx + " | " + txyc_mbhy +  " | " + fv_cmd + " > /dev/null && " + spbof_traj + " && " + spbof_hog + " && " + spbof_hof + " && " + spbof_mbhx + " && " + spbof_mbhy + " && " + record_cmd + ") 1>/dev/null 2>/dev/null"
    print "(" + cd + " && ( " + traj_cmd + " && " + traj_skip3_cmd + " && " + traj_skip6_cmd + " ) | " + txyc_cmd + " | " + fv_xyt_256_nosp_cmd + " | " + ensemble_fv_cmd + " > /dev/null && " + spbof_cmd + " && " + spbof_map_cmd + " && " + txyc_clean_cmd + " && " + record_cmd + ") 1>/dev/null 2>/dev/null"
    #print "(" + cd + " && " + traj_cmd + " | " + sfv_4_cmd + " | " + sfv_8_cmd + " | " + sfv_16_cmd + " | " + fv_128_nosp_cmd + " | " + fv_128_sp_cmd + " | " + fv_512_nosp_cmd + " | " + fv_1024_nosp_cmd + " | " + fv_xy_128_nosp_cmd + " | " + fv_xy_128_sp_cmd + " | " + fv_xy_256_nosp_cmd + " | " +  fv_xy_256_sp_cmd + " | " + fv_xy_512_nosp_cmd + " | " + fv_xy_1024_nosp_cmd + " | " + fv_xyt_128_nosp_cmd + " | " + fv_xyt_128_sp_cmd + " | " + fv_xyt_256_nosp_cmd + " | " + fv_xyt_256_sp_cmd + " | " + fv_xyt_512_nosp_cmd + " | " + fv_xyt_1024_nosp_cmd + " > /dev/null " + " && " + record_cmd + ") 1>/dev/null 2>/dev/null"
