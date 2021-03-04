# -*- coding: utf-8 -*-
"""
Created on Fri Dec  7 20:50:37 2018

@author: HP
"""

#import numpy as np
import cv2

cap=cv2.VideoCapture(0)
vdotype=cv2.VideoWriter_fourcc(*'XVID')
out=cv2.VideoWriter(r"C:\Users\HP\Downloads\flower1.avi",vdotype,24.0,(640,480))
while(1):
    ret,frame=cap.read()
    cv2.imshow('frame',frame)
    frame=cv2.flip(frame,0)
    gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    cv2.imshow('frame',gray)
    out.write(gray)
    if cv2.waitKey(1)==ord('q'):
        break
    
cap.release()
out.release()
cv2.destroyAllWindows()