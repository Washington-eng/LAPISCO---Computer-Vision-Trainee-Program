import cv2 as cv
import numpy as np

img = cv.imread('circulo.jpg')
imgGray = cv.cvtColor(img,cv.COLOR_RGB2GRAY)

filled = 1

imgRegion = np.zeros(imgGray.shape[:2], dtype=np.uint8)
imgRegion[149,119]=255

while(filled!=0):
    filled=0

    for i in range(0,imgGray.shape[0]):
        for j in range(0,imgGray.shape[1]):
            if imgRegion[i,j]==255:
                for x in range(-1,2):
                    for y in range(-1,2):
                        if imgGray[i+x,j+y]<127 and imgRegion[i+x,j+y]!=255:
                                imgRegion[i+x,j+y]=255
                                filled+=1
                                #cv.imshow('imgRegion', imgRegion)
                                #cv.waitKey(1)



cv.imshow('gray',imgGray)
cv.imshow('imgRegion', imgRegion)
cv.waitKey(0)


