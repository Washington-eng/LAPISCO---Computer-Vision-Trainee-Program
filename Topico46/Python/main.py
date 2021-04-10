import cv2 as cv
import glob
import numpy as np
import csv
if __name__ == '__main__':

    for path in glob.glob("Images/*jpg"):
        print(path)

        moments = []

        img = cv.imread(path)
        imgGray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
        cv.imshow("Image", imgGray)
        cv.waitKey(1000)

        moments = cv.moments(imgGray)

        #moment_to_write = np.empty(len(moments))


        moment_to_write = list(moments.values())
        print(moment_to_write)

        with open('Moments.csv','a+',newline='') as csvfile:
            ToWrite = csv.writer(csvfile)
            ToWrite.writerow(moment_to_write)


