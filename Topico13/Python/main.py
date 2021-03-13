import cv2 as cv
import numpy as np
import math

img = cv.imread('Image.png')
img_gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow('Imagem de entrada',img)

(rows,cols) = img_gray.shape[:2]

matrix=np.zeros((rows,cols),np.uint8)
Sobel = np.zeros((rows,cols),np.uint8)

dx=np.array([[-1,0,1],[-2,0,2],[-1,-0,1]])
dy=np.array([[1,2,1],[0,0,0],[-1,-2,-1]])

for i in range(rows):
    for j in range(cols):
        matrix[i,j] = img_gray[i,j]

mx=cv.filter2D(matrix,-1,dx)
my=cv.filter2D(matrix,-1,dy)

for i in range(rows):
    for j in range(cols):
        Sobel[i,j]=int(math.sqrt(pow(mx[i,j],2)+pow(my[i,j],2)))

#cv.imshow('my',my)
#cv.imshow('mx',mx)
cv.imshow('Sobel',Sobel)
cv.imwrite('Sobel.png',Sobel)

cv.waitKey(0)

