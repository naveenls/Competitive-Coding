# -*- coding: utf-8 -*-
"""
Created on Sat Feb  9 22:09:48 2019

@author: HP
"""

import cv2
import numpy as np
 
img = cv2.imread(r'C:\Users\HP\Downloads\abc.jpg')
rows, cols, ch = img.shape
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
blurred = cv2.GaussianBlur(gray, (5, 5), 0)
corners=cv2.goodFeaturesToTrack(gray,5,0.15,200)
corners=np.int0(corners)
a,b,p,q,r,s,t,u=corners.ravel()
pts1=np.float32([[p,q],[r,s],[t,u]])
#for corner in corners:
#    x,y=corner.ravel()
cv2.circle(img,(p,q),3,(255,0,0),-1)
cv2.circle(img,(r,s),3,(255,0,0),-1)
cv2.circle(img,(t,u),3,(255,0,0),-1)
pts2=np.float32([[644,649],[0,649],[644,200]])
matrix = cv2.getAffineTransform(pts1, pts2)
result = cv2.warpAffine(img, matrix, (cols, rows))
cv2.imshow("Image", img)
cv2.imshow("Affine transformation", result)
if cv2.waitKey(0)==ord('q'):
    cv2.destroyAllWindows()
 