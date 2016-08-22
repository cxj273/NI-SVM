#!/usr/bin/env python2.7
import sys
import os

def main(argv):
    if len(argv) is not 2:
        print "Usage: check_gz.py gz_list record_path"
        sys.exit(1)

    record_path = argv[1]
    cd = "cd " + os.getcwd()
    with open(argv[0], 'r') as gz_file:
        for line in gz_file:
            path = line.rstrip("\n")
            name = (path.split("/")[-1]).split(".")[0]
            print "( " + cd + " && gunzip -t " + path + " && touch " + record_path + "/" + name + ".record" + ") 1>/dev/null 2>/dev/null"

if __name__ == "__main__":
    main(sys.argv[1:])
