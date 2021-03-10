import cv2 as cv

image = cv.imread("Imagem.png")
image_HSV=cv.cvtColor(image,cv.COLOR_BGR2HSV)
H_channel,S_channel,V_channel=cv.split(image_HSV)

cv.imshow("H Channel",H_channel)
cv.imshow("S Channel",S_channel)
cv.imshow("V Channel",V_channel)
cv.waitKey(0)

cv.imwrite("H Channel.png",H_channel)
cv.imwrite("S Channel.png",S_channel)
cv.imwrite("V Channel.png",V_channel)