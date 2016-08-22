#!/usr/bin/env python2.7
import os
import sys

def main( argv ):
    if len(argv) < 4:
        print "Usage: merge_kernels.py row_num col_num output_file src_file1 src_file2 ..."
        sys.exit(1)

    row_num = int(argv[0])
    col_num = int(argv[1])
    output_file = open(argv[2], 'w')

    src_file = [ open(f,'r').readlines() for f in argv[3:] ]
    kernel = [[0 for i in range(col_num+1)] for j in range(row_num)]

    for f in src_file:
        sum = 0.0
        count = 0
        for line in f:
            for item in line.split():
                comb = item.split(':')
                index = int(comb[0])
                dist = float(comb[1])
                if index != 0:
                    sum += dist
                    count += 1
        avg = sum / count

        line_num = 0
        for line in f:
            for item in line.split():
                comb = item.split(':')
                index = int(comb[0])
                dist = float(comb[1])

                if index != 0:
                    kernel[line_num][index] += dist/avg
                else:
                    kernel[line_num][0] = line_num + 1
            line_num += 1

    for line in kernel:
        content = ' '.join([str(index) + ":" + str(value) for index, value in zip(range(len(line)), line)])
        output_file.write(content)
        output_file.write('\n')

    output_file.close()

if __name__ == '__main__':
    main(sys.argv[1:])

