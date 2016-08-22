#!/usr/bin/env python2.7
import os
import sys

def main( argv ):
    if len(argv) != 2:
        print "Usage: accuracy.py ground_truth predict_result"
        sys.exit(1)

    ground_truth_path = argv[0]
    predict_result_path = argv[1]

    ground_truth_file = open( ground_truth_path, 'r')
    predict_result_file = open( predict_result_path, 'r')

    num_data = 0
    correct_data = 0
    ground_truth = [line.split()[0] for line in ground_truth_file.readlines()]
    predict_result = [line.split()[0] for line in predict_result_file.readlines()[1:]]

    for truth, predict in zip(ground_truth, predict_result):
        print "Truth: " + truth + "\tPredict: " + predict
        if truth == predict:
            correct_data += 1
        num_data += 1
    print "accuracy: " + str(float(correct_data)/num_data) + " " + str(correct_data) + "/" + str(num_data)

if __name__ == '__main__':
    main(sys.argv[1:])

