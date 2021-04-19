def Equalize(img):
    import numpy as np
    (rows, cols) = img.shape[:2]

    a=np.zeros((256), dtype=np.uint8)
    p=np.zeros((256), dtype=np.float)
    s=np.zeros((256), dtype=np.float)
    img2 = img

    for i in range(rows):
        for j in range(cols):
            a[img[i, j]] =a[img[i, j]]+ 1

    for i in range(0, 255):
        p[i] = float(a[i]/(rows*cols))

    for i in range(0, 255):
        j=0
        aux = 0
        while(j<=i):
            aux = aux + p[j]
            j+=1
        s[i]=round(255*aux)

    for i in range(rows):
        for j in range(cols):
            img2[i,j]=s[img[i,j]]

    return img2


