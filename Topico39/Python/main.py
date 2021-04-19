import cv2 as cv
import numpy as np

if __name__ == '__main__':

    img = cv.imread('imagem.png')
    imgGray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)

    retval, imgOTSU = cv.threshold(imgGray,0,255,cv.THRESH_OTSU)

    kernel = cv.getStructuringElement(cv.MORPH_RECT,(1,3))

    for i in range(5):
        imgErode = cv.erode(imgOTSU,kernel,iterations=i)
        cv.imshow('imgDilate', imgErode)
        cv.waitKey(1000)

    cv.imshow('Gray',imgGray)
    cv.imshow('ImgOTSU',imgOTSU)
    cv.waitKey(0)