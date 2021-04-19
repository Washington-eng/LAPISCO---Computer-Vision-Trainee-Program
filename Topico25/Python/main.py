import cv2 as cv
import numpy as np

seed = (0,0)



def GrowingRegion(img,NRegions):
    global seed
    for a in range(0,NRegions):
        imgGray = cv.cvtColor(img, cv.COLOR_RGB2GRAY)
        cv.namedWindow('Regions', 1)
        cv.imshow('Regions', imgGray)
        cv.setMouseCallback('Regions', mouse_event)
        cv.waitKey(0)
        cv.destroyAllWindows()

        if a==0:
            imgRegion = np.zeros_like(img)

        filled = 0
        filled_final = 1
        X,Y=seed


        imgRegion[X,Y,a] = 255

        while (filled != filled_final):
            filled_final=filled
            filled = 0

            for i in range(0, imgGray.shape[0]):
                for j in range(0, imgGray.shape[1]):
                    if imgGray[i, j] <150:
                       if a == 0:
                           if(imgRegion[i,j,a]==255):
                               filled =ScanCloser(imgRegion, imgGray,i,j,a,filled)
                              
                       elif a == 1:
                           if (imgRegion[i, j, a] == 255):
                               filled = ScanCloser(imgRegion, imgGray, i, j, a, filled)

                       elif a ==2:
                           if (imgRegion[i, j, a] == 255):
                               filled = ScanCloser(imgRegion, imgGray, i, j, a, filled)


    return imgRegion


def ScanCloser(img_, img_Gray , i_ , j_ ,channel_ , filled_):
    for x in range(-1,2):
        for y in range(-1,2):
            if(img_Gray[i_+x,j_+y]<127) & img_[i_+x,j_+y,channel_]==0:
                img_[i_+x,j_+y,channel_]=255
                filled_+=1

    return filled_

def mouse_event(event,x,y,flags,param):
    if event==cv.EVENT_LBUTTONDOWN:
        global seed
        seed = (y,x)

if __name__ == '__main__':
    seed=(0,0)
    imagem=cv.imread('Formas.jpg')

    #cv.destroyAllWindows()

    img = GrowingRegion(imagem,3)

    cv.imshow('Region',img)
    cv.waitKey(0)
