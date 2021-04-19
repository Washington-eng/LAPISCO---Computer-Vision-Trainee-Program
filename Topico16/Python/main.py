import cv2 as cv
import matplotlib.pyplot as plt

img = cv.imread('Imagem.png')

img_gray = cv.cvtColor(img,cv.COLOR_BGRA2GRAY)

img_Equa = cv.equalizeHist(img_gray)

img_hist=cv.calcHist(img_gray, channels=[0], mask=None, histSize=[256], ranges=[0,256])
img_Equa_hist=cv.calcHist(img_Equa, channels=[0], mask=None, histSize=[256], ranges=[0,256])

plt.figure(1)
plt.subplot(221)
plt.imshow(img_gray, cmap='gray')
plt.subplot(222)
plt.hist(img_hist.ravel(), 256, [0, 256])
plt.subplot(223)
plt.imshow(img_Equa, cmap='gray')
plt.subplot(224)
plt.hist(img_Equa_hist.ravel(), 256, [0, 256])
plt.show()
