import cv2 as cv
import numpy as np


seed=(0,0)
def GrowingRegion(img,seed):

    filled = 1

    imgRegion = np.zeros_like(img)
    X=seed[0]
    Y=seed[1]

    imgRegion[X, Y, 0] = 255
    imgRegion[X, Y, 1] = 255
    imgRegion[X, Y, 2] = 255

    while (filled != 0):
        filled = 0

        for i in range(0, img.shape[0]):
            for j in range(0, img.shape[1]):
                if (imgRegion[i, j,0] == 255 & imgRegion[i, j,1] == 255 & imgRegion[i, j,2] == 255):
                    for x in range(-1, 2):
                        for y in range(-1, 2):
                            if (img[i+x,j+y,0]<127) and (img[i+x,j+y,1]<127) and (img[i+x,j+y,2]<127):
                                imgRegion[i + x, j + y,0] = 255
                                imgRegion[i + x, j + y,1] = 255
                                imgRegion[i + x, j + y,2] = 255
                                filled += 1
                                #cv.imshow('imgRegion', imgRegion)
                                #cv.waitKey(1)

    return imgRegion

def mouse_event(event,x,y,flags,param):
    if event==cv.EVENT_LBUTTONDOWN:
        global seed
        seed = (y,x)




if __name__ == '__main__':
    imagem=cv.imread('gatos.jpg')

    imagem = cv.resize(imagem,(0,0),fx=0.3,fy=0.3)
    #imgGray = cv.cvtColor(imagem, cv.COLOR_RGB2GRAY)
    cv.namedWindow('Circulo',1)
    cv.imshow('Circulo',imagem)
    cv.setMouseCallback('Circulo',mouse_event)
    cv.waitKey(0)
    cv.destroyAllWindows()

    img = GrowingRegion(imagem,seed)

    cv.imshow('Region',img)
    cv.waitKey(0)


