import cv2 as cv

camera = cv.VideoCapture(0)

while 1:
    (ret, frame) = camera.read()

    frame_gray = cv.cvtColor(frame, cv.COLOR_BGRA2GRAY)
    frame_canny=cv.Canny(frame_gray,50,80)

    cv.imshow('Canny',frame_canny)

    if cv.waitKey(1) & 0xFF==ord('q'):
        break

camera.release()