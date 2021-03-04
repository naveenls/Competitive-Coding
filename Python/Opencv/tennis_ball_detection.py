# -*- coding: utf-8 -*-
"""
Created on Thu Mar  7 01:02:33 2019

@author: HP
"""

import cv2
import numpy as np
import imutils

cap = cv2.VideoCapture(0)

while(True):

    _, frame = cap.read()
    
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # define range of green color in HSV
    lower_green = np.array([28, 154, 51])
    upper_green = np.array([36, 255, 255])

    # Threshold the HSV image to get only green colors
    mask1 = cv2.inRange(hsv, lower_green, upper_green)

    # Bitwise-AND mask and original image
    mask = cv2.erode(mask1, None, iterations=2)
    mask = cv2.dilate(mask, None, iterations=2)
    cnts=cv2.findContours(mask.copy(),cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    cnts=imutils.grab_contours(cnts)
    
    if(len(cnts)>0):
        cnt = max(cnts, key=cv2.contourArea)
        arclen=cv2.arcLength(cnt,True)
        approx=cv2.approxPolyDP(cnt,0.015*arclen,True)
        if(len(approx)>5):
            if cv2.contourArea(cnt) > 200:
                ((x, y), radius) = cv2.minEnclosingCircle(cnt)
                cv2.circle(frame,(int(x),int(y)),int(radius), (255, 0, 0), 2)
    cv2.imshow('frame',frame)
    if cv2.waitKey(1)==ord('q'):
        break
cap.release()
cv2.destroyAllWindows()