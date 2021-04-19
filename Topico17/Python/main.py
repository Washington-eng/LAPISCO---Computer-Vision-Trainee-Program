import cv2 as cv
'''
def Equalize(img):
    import numpy as np
    (rows, cols) = img.shape[:2]

    a=np.zeros((256), dtype=np.uint8)
    p=np.zeros((256), dtype=np.float32)
    s=np.zeros((256), dtype=np.uint8)
    img2 = np.zeros((rows,cols),dtype=np.uint8)
    aux=float(0)

    for i in range(rows):
        for j in range(cols):
            a[img[i, j]] += 1

    for i in range(0, 256):
        p[i] = float(a[i]/(rows*cols))

    for i in range(0, 256):
        j=0
        while(j<=i):
            aux =aux + p[j]
            j+=1
        s[i]=round(255*aux)
        aux=0

    for i in range(rows):
        for j in range(cols):
            img2[i,j]=s[img[i,j]]

    return img2
'''

def histogram(img):
    import numpy as np
    a=np.zeros([256],dtype=np.uint8)
    cont=int(0)
    max=int(0)
    (rows,cols)=img.shape[:2]

    for i in range(0,rows):
        for j in range(0,cols):
            a[img[i,j]]+=1
            cont+=1

    for i in range(0,256):
            if max<a[i]:
                max=a[i]

    for i in range(0,256):
        a[i] =(a[i])*100/max

    hist=np.zeros((100,256),dtype=np.uint8)
    rows,cols = hist.shape[:2]

    for j in range(0,cols):
        for i in range(0,rows):
            if (i>=(rows - a[j])):
                hist[i,j]=0
            else:
                hist[i,j]=255

    return hist

def Equalize(auxiliar):
    import numpy as np
    (M,N)= auxiliar.shape[:2]
    p = np.zeros([256],dtype=np.float)
    a = np.zeros([256],dtype=np.uint8)
    s = np.zeros([ 256], dtype=np.uint8)
    aux = float(0)
    max = int(0)

    auxiliar2 = np.zeros([M,N],dtype=np.uint8)

    for i in range(0,M):
        for j in range(0,N):
            valor = auxiliar[i,j]
            a[auxiliar[i,j]]= a[auxiliar[i,j]]+1

    for i in range(0,256):
        p[i]=a[i]/(M*N)

    for i in range(0,256):
        j=0
        while(j<=i):
            aux = aux + p[j]
            j=j+1
        s[i] = round(255*aux)
        aux=0

    for i in range(0,M):
        for j in range(0,N):
            auxiliar2[i,j]=s[auxiliar[i,j]]

    return auxiliar2


img = cv.imread('Imagem.png')

img_gray=cv.cvtColor(img,cv.COLOR_BGR2GRAY)

imgEqu=Equalize(img_gray)

grayHist=histogram(img_gray)
imgEquaHist=histogram(imgEqu)
cv.imshow('gray',img_gray)
cv.imshow('equa',imgEqu)
cv.imshow('img histogram',grayHist)

cv.imshow('eq histogram',imgEquaHist)
cv.waitKey(0)