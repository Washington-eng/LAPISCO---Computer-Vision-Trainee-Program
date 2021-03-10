import cv2 as cv

img = cv.imread("Imagem.png")

img_gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow("Gray image",img_gray)

height,width=img_gray.shape[:2]
img_gray_half=cv.resize(img_gray,(int(height/2),int(width/2)),cv.INTER_LINEAR)
img_gray_double=cv.resize(img_gray,(2*height,2*width),cv.INTER_LINEAR)

cv.imshow("Gray image(0.5)",img_gray_half)
cv.imshow("Gray image(2)",img_gray_double)
cv.waitKey(0)

cv.imwrite("Gray image(0.5)",img_gray_half)
cv.imwrite("Gray image(2)",img_gray_double)