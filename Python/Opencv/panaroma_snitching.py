# -*- coding: utf-8 -*-
"""
Created on Wed Mar 13 23:20:40 2019

@author: HP
"""

# -*- coding: utf-8 -*-
"""
Created on Mon Mar 11 15:40:20 2019

@author: HP
"""

import cv2
import numpy as np

img1=cv2.imread(r'F:\CS Projects\Coding\Python\Input\door_right.jpg',0)
img2=cv2.imread(r'F:\CS Projects\Coding\Python\Input\door_left.jpg',0)

sift=cv2.xfeatures2d.SIFT_create()
#surf=cv2.xfeatures2d.SURF_create()

orb=cv2.ORB_create()

kp1,des1=sift.detectAndCompute(img1,None)
kp2,des2=sift.detectAndCompute(img2,None)

#img=cv2.drawKeypoints(img,key_point,None)

bf=cv2.BFMatcher(cv2.NORM_HAMMING,crossCheck=True)
bf1=cv2.BFMatcher()
matches=bf1.knnMatch(des1,des2,k=2)
#matches=sorted(matches,key =lambda x:x.distance)
good = []
good1=[]
for m in matches:
    if m[0].distance < 0.5*m[1].distance:
        good.append((m[0].trainIdx, m[0].queryIdx))
        good1.append([m[0]])
matching_result=cv2.drawMatchesKnn(img1,kp1,img2,kp2,good1,None,flags=2)
if len(good)>4:
    ptsa=np.float32([kp1[i].pt for (_, i) in good]).reshape(-1,1,2)
    ptsb=np.float32([kp2[i].pt for (i, _) in good]).reshape(-1,1,2)
    H, masked = cv2.findHomography(ptsa, ptsb, cv2.RANSAC, 5.0)
    result = cv2.warpPerspective(img1, H,(img1.shape[1] + img2.shape[1], img2.shape[0]))
    result1=result.copy()
    result1[0:img2.shape[0], 0:img2.shape[1]] = img2
#kernel = np.ones((5,5),np.float32)/25
#result1 = cv2.filter2D(result1,-1,kernel)
cv2.imshow('hi',matching_result)
cv2.imshow('image',result)
cv2.imshow('image1',result1)

cv2.waitKey(0)

cv2.destroyAllWindows()