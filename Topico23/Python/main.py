import cv2 as cv
import numpy as np

seed=(0,0)

def GrowingRegion(img,seed):

    filled = 1

    imgRegion = np.zeros(imgGray.shape[:2], dtype=np.uint8)
    X=seed[0]
    Y=seed[1]
    imgRegion[X,Y] = 255

    while (filled != 0):
        filled = 0

        for i in range(0, imgGray.shape[0]):
            for j in range(0, imgGray.shape[1]):
                if imgRegion[i, j] == 255:
                    for x in range(-1, 2):
                        for y in range(-1, 2):
                            if imgGray[i + x, j + y] < 127 and imgRegion[i + x, j + y] != 255:
                                imgRegion[i + x, j + y] = 255
                                filled += 1
                                # cv.imshow('imgRegion', imgRegion)
                                # cv.waitKey(1)

    return imgRegion

def mouse_event(event,x,y,flags,param):
    if event==cv.EVENT_LBUTTONDOWN:
        global seed
        seed = (y,x)




if __name__ == '__main__':
    imagem=cv.imread('Corvo.jpg')
    imgGray = cv.cvtColor(imagem, cv.COLOR_RGB2GRAY)
    cv.namedWindow('Circulo',1)
    cv.imshow('Circulo',imgGray)
    cv.setMouseCallback('Circulo',mouse_event)
    cv.waitKey(0)
    cv.destroyAllWindows()

    img = GrowingRegion(imgGray,seed)

    cv.imshow('Region',img)
    cv.waitKey(0)
