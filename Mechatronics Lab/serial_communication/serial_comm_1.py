import serial
import time
import msvcrt
ser = serial.Serial('com5', timeout =0.001)

# ! part 1
while True:
    # num = ser.inWaiting()
    # x = ser.read(num)
    # print(type(x))
    # print(len(x))
    # print(x)
    # time.sleep(0.002)

# ! part 2
    if msvcrt.kbhit():
        key = msvcrt.getch()
        if (key == b'q' or key == b'w'):
            ser.write(key)
ser.close()