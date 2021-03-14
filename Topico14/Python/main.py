import cv2 as cv
import numpy as np

camera = cv.VideoCapture(0)

while 1:
    (ret,frame)= camera.read()

    frame_gray = cv.cvtColor(frame,cv.COLOR_BGR2GRAY)

    cv.imshow('camera',frame_gray)

    if cv.waitKey(1) & 0xFF== ord('q'):
        break

camera.release()