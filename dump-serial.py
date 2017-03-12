!/usr/bin/python
# -*- coding: utf-8 -*-


import serial
import time

ser = serial.Serial('/dev/ttyACM0', 115200)

while 1 :
    print(ser.readline())
    time.sleep(0.5)