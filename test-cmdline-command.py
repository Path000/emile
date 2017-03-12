#!/usr/bin/python
# -*- coding: utf-8 -*-


import serial
import sys
print sys.argv[1]

ser = serial.Serial('/dev/ttyACM0', 115200)
ser.write(sys.argv[1])

while 1 :
    print(ser.readline())
    time.sleep(0.5)