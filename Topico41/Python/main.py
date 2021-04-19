import cv2 as cv
import numpy as np
if __name__ == '__main__':

    img = cv.imread('Imagem.jpg')
    imgGray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)

    imgCanny = cv.Canny(imgGray,100,200)

    parameters = cv.SimpleBlobDetector_Params()

    #change thresholds
    parameters.minThreshold = 50
    parameters.maxThreshold = 250

    #Filter by area
    parameters.filterByArea = True
    parameters.minArea = 10

    #filter by circularity
    parameters.filterByCircularity = True
    parameters.minCircularity = 0.1

    #filter by convexity
    parameters.filterByConvexity = True
    parameters.minConvexity = 0.50

    #filter by inertia
    parameters.filterByInertia = True
    parameters.minInertiaRatio = 0.01

    #Distance between blobs
    parameters.minDistBetweenBlobs = 10

    detector = cv.SimpleBlobDetector_create(parameters)
    blobs = detector.detect(imgCanny)
    
    img_with_keypoints = cv.drawKeypoints(imgGray, blobs, np.array([]), (0, 0, 255),
                                         cv.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
    print(" number of objects : " + str(len(blobs)))

    cv.imshow("original", img)
    cv.imshow('Canny', imgCanny)
    cv.imshow('keypoints',img_with_keypoints)
    cv.waitKey(0)
