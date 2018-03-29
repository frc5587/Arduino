from networktables import NetworkTables
import serial
import time

# To see messages from networktables, you must setup logging
import logging
logging.basicConfig(level=logging.DEBUG)

NetworkTables.initialize(server="172.22.11.2")

ser = serial.Serial("COM4", 9600)   # open serial port that Arduino is using

dt = NetworkTables.getTable("dataTable")

while True:
    if dt.getBoolean("Match Started", None):
        print(dt.getBoolean("Match Started", None))
        print ("Sending serial data")
        time.sleep(2)
        ser.write(b"s")


