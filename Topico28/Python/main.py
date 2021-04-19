import cv2 as cv
import numpy as np

if __name__ == '__main__':

    img = cv.imread('Imagem.png')
    imgGray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
    imgThresh = cv.adaptiveThreshold(imgGray,255,cv.ADAPTIVE_THRESH_GAUSSIAN_C,cv.THRESH_BINARY,3,4)

    cv.imshow('Modified image',imgThresh)
    cv.waitKey(0)
