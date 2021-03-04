# -*- coding: utf-8 -*-
"""
Created on Mon Mar 11 15:40:20 2019

@author: HP
"""

import cv2
import numpy as np
lst=[1,2,3,4,5,6]

img1=cv2.imread(r'F:\CS Projects\Coding\Python\Input\the_book_thief.jpg',0)
img2=cv2.imread(r'F:\CS Projects\Coding\Python\Input\me_holding_book.jpg',0)


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
for m,n in matches:
    if m.distance < 0.5*n.distance:
        good.append([m])
        good1.append((m.trainIdx, m.queryIdx))
        
matching_result=cv2.drawMatchesKnn(img1,kp1,img2,kp2,good,None,flags=2)
cv2.imshow('image',matching_result)

ptsa=np.float32([kp1[i].pt for (_, i) in good1]).reshape(-1,1,2)
ptsb=np.float32([kp2[i].pt for (i, _) in good1]).reshape(-1,1,2)
H, masked = cv2.findHomography(ptsa, ptsb, cv2.RANSAC, 5.0)
result = cv2.warpPerspective(img1, H,(img2.shape[1],img2.shape[0]))
cv2.addWeighted(result, 0.2, img2, 0.8,0, result)

cv2.imshow('result',result)
if cv2.waitKey(0)==ord('q'):
    cv2.destroyAllWindows()