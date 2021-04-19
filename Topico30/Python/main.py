import cv2 as cv
import numpy as np

if __name__ == '__main__':

    img = cv.imread('Image.jpg')
    imgGray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

    imgCanny = cv.Canny(imgGray,50,100)

    (contours, hierarchy) = cv.findContours(imgCanny,cv.RETR_TREE,cv.CHAIN_APPROX_SIMPLE)

    cv.drawContours(img,contours,-1,(0,255,0),2)

    #cv.imshow('Canny',imgCanny)
    cv.imshow('Final Image', img)
    cv.waitKey(0)