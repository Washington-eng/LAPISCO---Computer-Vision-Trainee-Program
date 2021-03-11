import cv2 as cv
import numpy as np

img=cv.imread('Imagem.png')
img_gray=cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow('Gray image',img_gray)
cv.waitKey(0)

rows,cols=img_gray.shape[:2]

matrix=np.zeros((rows,cols),dtype=np.uint8)

for i in range(rows):
    for j in range(cols):
        matrix[i,j]=img_gray[i,j]


with open('matriz.txt','w') as file:
    for i in range(rows):
        for j in range(cols):
            if matrix[i,j] < 127:
                matrix[i,j]=0
            else:
                matrix[i,j]=255

            file.write(str(matrix[i,j])+' ')
        file.write('\n')


