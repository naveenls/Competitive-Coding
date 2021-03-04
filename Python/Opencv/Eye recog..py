# -*- coding: utf-8 -*-
"""
Created on Sat Dec  8 00:06:45 2018

@author: HP
"""

import cv2

eye_cascade = cv2.CascadeClassifier(r'F:\CS Projects\Coding\Python\Input\eyerecog.xml')
vdotype=cv2.VideoWriter_fourcc(*'XVID')
out=cv2.VideoWriter(r"C:\Users\HP\Downloads\face.avi",vdotype,24,(640,480))

cap = cv2.VideoCapture(0)

while(True):
    # Capture frame-by-frame
    ret, frame = cap.read()
    gray  = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    eye = eye_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=1)
    for (x, y, w, h) in eye:
    	print(eye)
    	color = (0, 255, 0) #BGR 0-255 
    	stroke = 2
    	cv2.rectangle(frame, (x, y), (x+w, y+h), color, stroke)
    	#subitems = smile_cascade.detectMultiScale(roi_gray)
    	#for (ex,ey,ew,eh) in subitems:
    	#	cv2.rectangle(roi_color,(ex,ey),(ex+ew,ey+eh),(0,255,0),2)
    # Display the resulting frame
    #out.write(frame)
    cv2.imshow('frame',frame)
    if cv2.waitKey(20) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
out.release()
cv2.destroyAllWindows()