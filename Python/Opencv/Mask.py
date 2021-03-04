# -*- coding: utf-8 -*-
"""
Created on Mon Jan  7 13:16:50 2019

@author: HP
"""

import cv2
import numpy as np

cap=cv2.VideoCapture(0)
while(True):
    ret,frame=cap.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    lower_blue = np.array([110,50,50])
    upper_blue = np.array([130,255,255])
    mask = cv2.inRange(hsv, lower_blue, upper_blue)
    res = cv2.bitwise_and(frame,frame, mask= mask)
    gray=cv2.cvtColor(res,cv2.COLOR_BGR2GRAY)
    corners=cv2.goodFeaturesToTrack(gray,100,0.5,10)
    corners=np.int0(corners)
    for corner in corners:
        x,y=corner.ravel()
        cv2.circle(frame,(x,y),3,(255,0,0),-1)
    cv2.imshow('frame',mask)
    if cv2.waitKey(1)==ord('q'):
        break
cap.release()
cv2.destroyAllWindows()