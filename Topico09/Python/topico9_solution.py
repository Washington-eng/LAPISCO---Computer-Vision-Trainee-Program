import cv2 as cv

img=cv.imread("Imagem.png")
img_gray=cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow("teste",img_gray)
cv.waitKey(0)

rows,cols=img_gray.shape[:2]

with open('teste.txt','w') as file:
    for i in range(rows):
        for j in range(cols):
            file.write(str(img_gray[i,j])+' ')
        file.write('\n')


