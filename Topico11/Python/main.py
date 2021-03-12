import cv2 as cv
import numpy as np

img = cv.imread('quadrado.png')
img_gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow('quadrado',img_gray)


rows,cols = img_gray.shape[:2]

matriz = np.zeros((rows,cols),dtype=np.uint8)

xc=0
yc=0
contador=0

for i in range(rows):
    for j in range(cols):
        matriz[i,j] = img_gray[i,j]
        if matriz[i,j]==0:
            xc+=i
            yc+=j
            contador+=1


xc=int(xc/contador)
yc=int(yc/contador)

cv.circle(img_gray,(xc,yc),3,(255,255,255))
cv.imshow('quadrado com centro marcado',img_gray)
cv.waitKey(0)