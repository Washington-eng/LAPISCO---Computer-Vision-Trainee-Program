import cv2 as cv
import numpy as np

if __name__ == '__main__':

    img = cv.imread('imagem.png')
    imgGray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)

    retval, imgOTSU = cv.threshold(imgGray,0,255,cv.THRESH_OTSU)

    kernel = cv.getStructuringElement(cv.MORPH_RECT,(1,3))
    print(kernel)
    for i in range(5):
        imgDilate = cv.dilate(imgOTSU,kernel,iterations=2)

    cv.imshow('Gray',imgGray)
    cv.imshow('ImgOTSU',imgOTSU)
    cv.imshow('imgDilate',imgDilate)
    cv.waitKey(0)