#!/usr/bin/python
# coding: UTF-8

import sys

line = sys.stdin.readline()
counter = 0

while line:
    counter = counter + len(line.decode('utf-8').rstrip())
    # print line
    # print counter
    line = sys.stdin.readline()

print counter
