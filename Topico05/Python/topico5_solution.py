import cv2 as cv

imag=cv.imread("Imagem.png")
cv.imshow("Original Image",imag)

imag_blur=cv.blur(imag,(3,3))
cv.imshow("Blur Image",imag_blur)

imag_mediaBlur=cv.medianBlur(imag,3)
cv.imshow("MedianBlur Imagem",imag_mediaBlur)
cv.waitKey(0)

