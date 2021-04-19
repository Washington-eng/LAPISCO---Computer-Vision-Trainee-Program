import cv2 as cv
import glob
import numpy as np
import csv

def get_moments(MOMENT,moment):
    moment_return = []
    if MOMENT == 'SPATIAL_MOMENTS':
        moment_return = moment[0:10]

    if MOMENT == 'CENTRAL_MOMENTS':
        moment_return = moment[10:17]

    if MOMENT == 'CENTRAL_NORMALIZED_MOMENTS':
        moment_return = moment[17:]

    return moment_return

if __name__ == '__main__':

    for path in glob.glob("Images/*jpg"):
        print(path)

        moments = []

        img = cv.imread(path)
        imgGray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
        cv.imshow("Image", imgGray)
        cv.waitKey(1000)

        moments = cv.moments(imgGray)
        #print(moments)
        #moment_to_write = np.empty(len(moments))


        moment_to_write = list(moments.values())

        moment_to_write = get_moments('CENTRAL_NORMALIZED_MOMENTS',moment_to_write)
        print(moment_to_write)

        with open('Moments.csv','a',newline='') as csvfile:
            ToWrite = csv.writer(csvfile)
            ToWrite.writerow(moment_to_write)


