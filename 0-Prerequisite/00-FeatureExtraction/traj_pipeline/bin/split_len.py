#!/usr/bin/env python2.7
import sys

def main(argv):
    if len(argv) != 2:
        print "split_feature.py src_feature len_split"
        exit(1)
    
    src_path = argv[0]
    len_split = map( float, argv[1].split(','))

    src_file = open(src_path,'r')

    len_1_file = open(src_path+"_len_1", 'w')
    len_2_file = open(src_path+"_len_2", 'w')
    len_3_file = open(src_path+"_len_3", 'w')
    len_4_file = open(src_path+"_len_4", 'w')
    len_1_2_file = open(src_path+"_len_1-2", 'w')
    len_3_4_file = open(src_path+"_len_3-4", 'w')

    len_pos = 5
    for line in src_file:
        length = float(line.split()[len_pos])

        if length < len_split[0]:
            len_1_file.write(line)
            len_1_2_file.write(line)
        elif length < len_split[1]:
            len_2_file.write(line)
            len_1_2_file.write(line)
        elif length < len_split[2]:
            len_3_file.write(line)
            len_3_4_file.write(line)
        else:
            len_4_file.write(line)
            len_3_4_file.write(line)

    src_file.close()
    len_1_file.close()
    len_2_file.close()
    len_3_file.close()
    len_4_file.close()
    len_1_2_file.close()
    len_3_4_file.close()

if __name__ == '__main__':
    main(sys.argv[1:])
