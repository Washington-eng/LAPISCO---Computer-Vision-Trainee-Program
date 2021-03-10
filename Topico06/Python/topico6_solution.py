import cv2 as cv

img = cv.imread("Imagem.png")
cv.imshow("Original Image",img)

img_gray=cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow("Gray Image",img_gray)

img_canny = cv.Canny(img_gray,100,200)
cv.imshow("Canny Image",img_canny)
cv.waitKey(0)

cv.imwrite("Canny Image.png",img_canny)

