import cv2 as cv
import matplotlib.pyplot as plt

img = cv.imread('Imagem.png')
imgGray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

Gx = cv.Sobel(src= imgGray,ddepth=cv.CV_64F,dx=1,dy=0,ksize=3)
Gy = cv.Sobel(src= imgGray,ddepth=cv.CV_64F,dx=0,dy=1,ksize=3)

imgSobel = cv.convertScaleAbs(((Gx**2)+(Gy**2))**(1/2))

#imgGrayHist = cv.calcHist(imgGray)
#imgSobelHist = cv. calcHist(imgSobel)

plt.figure(1)
plt.subplot(221)
plt.imshow(imgGray,cmap='gray')
plt.subplot(222)
plt.hist(imgGray.ravel(),256,[0,256])
plt.subplot(223)
plt.imshow(imgSobel,cmap='gray')
plt.subplot(224)
plt.hist(imgSobel.ravel(),256,[0,256])
plt.show()