# -*- coding: utf-8 -*-
"""
Created on Sun Dec  1 00:22:09 2019

@author: HP
"""

import cv2

num=cv2.imread(r'F:\CS Projects\Coding\Python\Input\Num_3.jpg')

a=5
b=6

dict={a:'hi',b:'hello'}
print(dict)
gray=cv2.cvtColor(num,cv2.COLOR_BGR2GRAY)
gray=cv2.GaussianBlur(gray,(7,7),0)

edge=cv2.Canny(gray,50,100)
#edge=cv2.dilate(edge,None,iterations=1)
#edge=cv2.erode(edge,None,iterations=1)

cv2.imshow('Number',edge)

if cv2.waitKey(0)==ord('q'):
    cv2.destroyAllWindows()