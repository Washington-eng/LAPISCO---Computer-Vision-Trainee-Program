
import numpy as np
import cv2 as cv

def get_pixel_value(img,center,x,y):
    new_value = 0

    try:
        if img[x,y]>= center:
            new_value = 1

    except:
        pass

    return new_value


def LBP_pixel(img,x,y):
    center = img[x][y]
    power_values = [1,2,4,8,16,32,64,128]
    values = []
    returned_value = 0

    for i in range(-1,2):
        for j in range(-1,2):
            if i==0 & j == 0:
                continue
            values.append(get_pixel_value(img,center,x+i,y+j))

    for i in range(len(values)):
        returned_value+=values[i]*power_values[i]

    return returned_value

def LBP(img):

    imgLBP = np.zeros((img.shape[:2]), dtype=np.uint8)

    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            imgLBP[i][j] = LBP_pixel(img,i,j)

    return imgLBP

if __name__ == '__main__':

    img = cv.imread('Image.png')

    imgGray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)

    imgLBP = LBP(imgGray)

    cv.imshow('Original GRAY ',imgGray)
    cv.imshow('LBP',imgLBP)
    cv.waitKey(0)