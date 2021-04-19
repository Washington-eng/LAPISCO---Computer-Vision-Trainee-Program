import cv2 as cv
import numpy as np
if __name__ == '__main__':

    img = cv.imread('Imagem.jpg')
    Row, Col = img.shape[:2]

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

    #print(crop)
    #cv.imshow("original", img)
    #cv.imshow('Canny', imgCanny)
    #cv.imshow('keypoints',img_with_keypoints)
    #cv.waitKey(0)
    #print(dir(blobs))
    #print(blobs)
    for index,i in enumerate(blobs):
        xc = i.pt[0]    #coordinate of center in x axis
        yc = i.pt[1]    #coordinate of center in y axis
        size = i.size   #Size of the diameter

        Top_left_X = int(xc - size/2 - 15)
        Top_left_Y = int(yc - size/2 - 15)
        #print(int(xc),int(yc),int(size))

        Bottom_right_X = int(xc + size/2 + 15)
        Bottom_right_Y = int(yc + size/2 + 15)

        #Bunch of tests to verify if the points(Top_left and Bottom_right) are inside the image boundaries

        if Top_left_X < 0:
            Top_left_X = 0

        if Top_left_Y < 0:
            Top_left_Y = 0

        if Bottom_right_X > Col:
            Bottom_right_X = Col

        if Bottom_right_Y > Row:
            Bottom_right_Y = Row

        Top_left = (Top_left_X,Top_left_Y)
        Bottom_right = (Bottom_right_X, Bottom_right_Y)

        cv.rectangle(img,Top_left,Bottom_right,(0,0,255),2)

    cv.imshow('Final Image',img)
    cv.waitKey(0)





