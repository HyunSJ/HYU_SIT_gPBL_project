##############################
# 2019.07.27
# HYU - SIT gPBL
# Posture correcting
# version 1,0
# author group D
# ############################


from numpy import *
import matplotlib.pyplot as plt

port = "/dev/rfcomm0"
bluetooth = serial.Serial(port, 115200)
bluetooth.flush()

good = 0
bad = 0

recived_data = [0,0]
posture_labels = ["GOOD", "BAD"]


while True :
##print(recived_data[0],recived_data[1])
bytesR = bluetooth.readline()
print(bytesR)
sensor_value = eval(bytesR)
if sensor_value == 0:
good += 1
recived_data[0] = good
else:
bad += 1
recived_data[1] = bad
plt.clf()
plt.axis("equal")
plt.pie(recived_data,
labels = posture_labels,
radius = 1.5,
autopct = '%0.1f%%',
explode = [0.001,0.001],
startangle=90,
colors = ['yellowgreen','lightcoral'])

plt.pause(0.1)
