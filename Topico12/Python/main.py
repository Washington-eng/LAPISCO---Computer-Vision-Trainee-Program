import cv2 as cv
import numpy as np

with open('matriz.txt','r') as file:

   matrix=[]

   for i,line in enumerate(file):       # i -> nº da linha          line-> obtém a linha(i)
       linha = line.split()             #faz com que a variável 'linha' se torne uma lista de strings,
                                        #sendo que cada valor string corresponde a 1 pixel da imagem
       for j,elemento in enumerate(linha):      #transforma cada elemento da lista de string 'linha' p/ tipo int
            linha[j]=int(elemento)              #dessa forma, ao final do for, teremos 'linha' como uma lista de int
       matrix.append(linha)


matrix=np.asarray(matrix,np.uint8)
cv.imshow('teste',matrix)
cv.waitKey(0)



