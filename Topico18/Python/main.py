import cv2 as cv

img = cv.imread('Imagem.png')

imgGray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)

imgLaplacian = cv.Laplacian(imgGray,ddepth=cv.CV_8U,ksize=3)

imgLaplacianEqualized = cv.equalizeHist(imgLaplacian)

cv.imshow('Gray image',imgGray)
cv.imshow('Laplacian',imgLaplacian)
cv.imshow('Laplacian Equalized',imgLaplacianEqualized)

cv.waitKey(0)