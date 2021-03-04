# -*- coding: utf-8 -*-
"""
Created on Wed Feb 27 21:57:03 2019

@author: HP
"""

import cv2
import imutils

img=cv2.imread(r'F:\CS Projects\Coding\Python\Input\shapes.jpg')
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
gray=cv2.GaussianBlur(gray,(7,7),0)

edge=cv2.Canny(gray,50,100)
edge=cv2.dilate(edge,None,iterations=1)
edge=cv2.erode(edge,None,iterations=1)

cnts=cv2.findContours(edge.copy(),cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
cnts=imutils.grab_contours(cnts)
copy=img.copy()
font=cv2.FONT_HERSHEY_SIMPLEX
fontScale=0.3
fontColor=(255,0,0)
lineType=1
for c in cnts:
    if cv2.contourArea(c)>100:
        arclen=cv2.arcLength(c,True)
        approx=cv2.approxPolyDP(c,0.015*arclen,True)
        shape="NONE"
        if len(approx)==3:
            shape="Triangle"
        elif len(approx)==4:
            (x,y,w,h)=cv2.boundingRect(approx)
            a=w/float(h)
            if a>=0.9 and a<=1.1:
                shape="Square"
            else:
                shape="Rectangle"
        elif len(approx)==5:
            shape="pentagon"
        else:
            shape="Circle"
        cv2.drawContours(copy,[approx],0,(0,255,0),6)
        print(shape)
        m=cv2.moments(approx)
        cx = int(m['m10']/m['m00'])
        cy = int(m['m01']/m['m00'])
        cv2.putText(copy,shape, (cx,cy), font, fontScale,fontColor,lineType)
cv2.imshow('frame',copy)
cv2.waitKey(0)
cv2.destroyAllWindows()
