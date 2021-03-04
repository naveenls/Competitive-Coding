# -*- coding: utf-8 -*-
"""
Created on Sat Feb  9 21:26:07 2019

@author: HP
"""

import cv2
import matplotlib.pyplot as plt

img = cv2.imread(r'C:\Users\HP\Downloads\sukoku.jpg')
img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
img1 = cv2.GaussianBlur(img, (5, 5), 0)
sobelx = cv2.Sobel(img,cv2.CV_64F,1,0,ksize=5)
sobely = cv2.Sobel(img,cv2.CV_64F,0,1,ksize=5)
laplacian = cv2.Laplacian(img,cv2.CV_64F)
cv2.imwrite(r'C:\Users\HP\Downloads\sukoku1.jpg',laplacian)

plt.subplot(221),plt.imshow(img,cmap='gray'),plt.axis('off'),plt.title('Original')
plt.subplot(222),plt.imshow(laplacian,cmap='gray'),plt.axis('off'),plt.title('Laplacian')
plt.subplot(223),plt.imshow(sobelx,cmap='gray'),plt.axis('off'),plt.title('SobelX')
plt.subplot(224),plt.imshow(sobely,cmap='gray'),plt.axis('off'),plt.title('SobelY')
plt.show()