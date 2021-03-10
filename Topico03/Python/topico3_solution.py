import cv2 as cv

image=cv.imread("Imagem.png")


B_channel,G_channel,R_channel=cv.split(image)

cv.imshow("B Channel",B_channel)
cv.imshow("G Channel",G_channel)
cv.imshow("R Channel",R_channel)
cv.waitKey(0)

cv.imwrite("B Channel.png",B_channel)
cv.imwrite("G Channel.png",G_channel)
cv.imwrite("R Channel.png",R_channel)