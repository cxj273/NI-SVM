#!/usr/bin/env python2.7
import os
import sys

def lf( target_path, src_path_list ):

    target_file = open(target_path, 'w')

    score_table = list()
    for p in src_path_list:
       f = open(p, 'r')
       flines = f.readlines()
       header = flines[0]
       #print header[-2]
       if header[-2] == "0": 
           score_table.append([[float(line.split()[1]), float(line.split()[2])] for line in flines[1:]])
       else:
           score_table.append([[float(line.split()[2]), float(line.split()[1])] for line in flines[1:]])

       f.close()

    target_score = [ [ sum(m)/len(src_path_list) for m in zip(*i)] for i in zip(*score_table)]

    target_file.write('labels 1 0\n')

    for p in target_score:
        
        pos_score = p[0]
        neg_score = p[1]
        label = 1 if pos_score > neg_score else 0
        target_file.write(str(label) + " " + str(pos_score) + " " + str(neg_score) + "\n")


    #print target_score
    #print score_table

    target_file.close()

def main( argv ):
    if len(argv) <= 3:
        print "Usage: avg_fusion.py num_class target_path src1 src2 ..."
        sys.exit(1)

    num_class = int(argv[0])
    target_path = argv[1]
    src_path_list = argv[2:]

    for n in range(1, 1+num_class):
        file_name = str(n) + "_output"
        lf(target_path + "/" + file_name, [x+"/"+file_name for x in src_path_list])

if __name__ == '__main__':
    main(sys.argv[1:])

