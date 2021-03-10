import cv2 as cv

image=cv.imread("Imagem.png")
gray_image=cv.cvtColor(image,cv.COLOR_BGR2GRAY)
cv.imshow("Gray image",gray_image)
cv.imwrite("Gray image.png",gray_image)
cv.waitKey(0)