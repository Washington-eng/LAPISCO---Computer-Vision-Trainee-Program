import cv2 as cv

image = cv.imread("Imagem.png")
cv.imshow("Imagem",image)
cv.imwrite("Imagem.png",image)
cv.waitKey(0)