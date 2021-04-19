import cv2 as cv
import numpy as np

if __name__=='__main__':
    img = cv.imread('Image.jpg')
    imgGray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
    imgGray = cv.GaussianBlur(imgGray,(5,5),3)

    circles = cv.HoughCircles(imgGray,cv.HOUGH_GRADIENT,1,20,param1=50,param2=30,minRadius=0,maxRadius=0)

    if circles is not None:
        circles = np.uint16(np.around(circles))
        for (x,y,R) in circles[0, :]:
            cv.circle(img,(x,y),R,(255,0,0),3)
            cv.circle(img,(x,y),2,(0,0,255),3)


    cv.imshow('Final',img)
    cv.waitKey(0)