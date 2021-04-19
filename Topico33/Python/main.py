import cv2 as cv
import numpy as np

if __name__ == '__main__':
    img = cv.imread('Image.jpg')
    imgGray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

    imgCanny = cv.Canny(imgGray, 50, 100)

    (contours, hierarchy) = cv.findContours(imgCanny, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)

    contoursPoly = [None]*len(contours)
    boundRect = [None]*len(contours)

    for i, contour in enumerate(contours):
        contoursPoly[i] = cv.approxPolyDP(contour,3,True)
        boundRect[i] = cv.boundingRect(contoursPoly[i])

    #x, y, w, h = cv2.boundingRect(cnt)     x-> coordenada x de onde inicia o retangulo
    #                                       y-> coordenada y de onde inicia o retangulo
    #                                       w-> largura do retangulo
    #                                       h-> alutra do retangulo
    #img = cv2.rectangle(img, (x, y), (x + w, y + h), (0, 255, 0), 2)
    for i, contour in enumerate(contoursPoly):
        cv.rectangle(img, (boundRect[i][0],boundRect[i][1]),(boundRect[i][0]+boundRect[i][2],
                     boundRect[i][1]+boundRect[i][3]),color = (0,255,0),thickness=2)

        window = img[boundRect[i][1]:boundRect[i][1]+boundRect[i][3],boundRect[i][0]:boundRect[i][0]+boundRect[i][2]]

    #cv.imshow('Canny',imgCanny)
        cv.imshow('Window'+str(i+1),window)

        cv.waitKey(0)
