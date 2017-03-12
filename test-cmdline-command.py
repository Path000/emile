#!/usr/bin/python
# -*- coding: utf-8 -*-

import serial
import sys

ser = serial.Serial('/dev/ttyACM0', 115200)
ser.write(sys.argv[1])
ser.write("\n")

try:
	while 1 :
		print(ser.readline())
		time.sleep(0.5)
except KeyboardInterrupt:
	print("Terminé")