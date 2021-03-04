# -*- coding: utf-8 -*-
"""
Created on Thu Feb 14 09:42:29 2019

@author: HP
"""

import cv2
import matplotlib.pyplot as plt

img = cv2.imread(r'F:\CS Projects\Coding\Python\Input\hi.jpg')
imggray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
blurred = cv2.GaussianBlur(imggray, (5, 5), 0)
canny = cv2.Canny(blurred,10,200)

canny1=cv2.cornerHarris(blurred,3,3,0.05)
img[canny1>0.01*canny1.max()]=[0,0,0]
#cv2.imwrite(r'C:\Users\HP\Downloads\chess2.jpg',canny)
#cv2.imwrite(r'C:\Users\HP\Downloads\chess3.jpg',img)
plt.subplot(221),plt.imshow(blurred,cmap='gray'),plt.axis('off'),plt.title('Original')
plt.subplot(222),plt.imshow(canny,cmap='gray'),plt.axis('off'),plt.title('Edges Detected by Canny')
plt.subplot(224),plt.imshow(img,cmap='gray'),plt.axis('off'),plt.title('corners1')
plt.show()