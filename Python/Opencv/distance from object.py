# -*- coding: utf-8 -*-
"""
Created on Tue Feb 26 22:55:36 2019

@author: HP
"""

from scipy.spatial import distance as dist
from imutils import perspective
from imutils import contours
import numpy as np
import imutils
import cv2

image = cv2.imread(r'F:\CS Projects\Coding\Python\Input\hi1.jpg')
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
gray = cv2.GaussianBlur(gray, (7, 7), 0)
 
# perform edge detection, then perform a dilation + erosion to
# close gaps in between object edges
edged = cv2.Canny(gray, 50, 100)
edged = cv2.dilate(edged, None, iterations=1)
edged = cv2.erode(edged, None, iterations=1)
cv2.imshow('edge',edged)
# find contours in the edge map
cnts = cv2.findContours(edged.copy(), cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
cnts = imutils.grab_contours(cnts)
pixelsPerMetric = 15*629
orig = image.copy()
c = max(cnts, key = cv2.contourArea)
rect = cv2.minAreaRect(c)
box = cv2.boxPoints(rect)
box = np.int0(box)
cv2.drawContours(orig,[box],0,(0,255,0),2)
box = perspective.order_points(box)
(tl, tr, br, bl) = box
print(pixelsPerMetric/dist.euclidean(tl, tr))
cv2.imshow('frame',orig)
cv2.waitKey(0)
cv2.destroyAllWindows()