import cv2 as cv

img = cv.imread("Imagem.png")

img_gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow("Gray Image",img_gray)

retval,img_thres = cv.threshold(img_gray,100,200,0)
cv.imshow("Thres Image",img_thres)
cv.waitKey(0)

cv.imwrite("threshold image.png",img_thres)