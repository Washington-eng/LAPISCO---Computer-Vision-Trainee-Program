import numpy as np
import cv2 as cv
import random

def GrowingRegion(img):

    (rows,cols) = img.shape[:2]

    Region = np.zeros_like(img)
    RegionRGB = np.zeros([img.shape[0], img.shape[1], 3], dtype=np.uint8)

    Objects = 0

    for i in range(rows):
        for j in range(cols):
            if Region[i,j] == 0 and img[i,j] == 0:
                Region[i,j] = 255
                Objects+=1
                color = [random.randrange(0,255) for i in range(3)]
                filled = 1
                filled_final = 0

                while(filled != filled_final):
                    filled_final = filled
                    for r in range(rows):
                        for c in range(cols):
                            if Region[r,c] == 255:
                                for x in range(-1,2):
                                    for y in range(-1,2):
                                        if img[r+x,c+y] <100 and Region[r+x,c+y] ==0:
                                            Region[r+x,c+y] = 255
                                            RegionRGB[r+x,c+y,0] = color[0]
                                            RegionRGB[r + x, c + y, 1] = color[1]
                                            RegionRGB[r + x, c + y, 2] = color[2]
                                            filled += 1

                    cv.imshow('Region',Region)
                    cv.waitKey(10)

    return Objects,Region, RegionRGB

if __name__ == '__main__':

    img = cv.imread('formas.jpg')
    cv.imshow('Original image',img)
    cv.waitKey(0)

    imgGray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
    Obj,Region,RegionRGB = GrowingRegion(imgGray)

    cv.imshow('Final image',RegionRGB)
    cv.waitKey(0)