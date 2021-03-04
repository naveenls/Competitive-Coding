# -*- coding: utf-8 -*-
"""
Created on Thu Jan 16 17:59:20 2020

@author: HP
"""
import math
from random import randint
import matplotlib.pyplot as plt

def cross(a,b):
    return a.x*b.y-b.x*a.y

class points:
    def __init__(self,x,y):
        self.x=x
        self.y=y
        self.used=False
        
    def __add__(self,other):
        return points(self.x+other.x,self.y+other.y)
    
    def __sub__(self,other):
        return points(self.x-other.x,self.y-other.y)
    
    def __repr__(self):
        return str(self.x) + ',' + str(self.y)
    
    def deter(self):
        return math.sqrt(self.x**2,self.y**2)
    
point=[[randint(1,100),randint(1,100)] for i in range(20)]
point=[points(a,b) for a,b in point]

convex_hull=[]

min_point=point[0]

for pnt in point:
    if pnt.x<min_point.x:
        min_point=pnt
        
convex_hull.append(min_point)
        
initial_pnt=min_point
min_point.used=True

p=min_point

while True:
    N=None
    for pnt in point:
        if not pnt.used:
            if N==None:
                N=pnt
            elif cross(pnt-p,N-p)<0:
                N=pnt
                
    if cross(initial_pnt-p,N-p)<0:
        break
    
    N.used=True
    convex_hull.append(N)
    p=N

convex_hull.append(initial_pnt)

plt.scatter([p.x for p in point],[p.y for p in point])
plt.plot([p.x for p in convex_hull],[p.y for p in convex_hull])

plt.show()   

    
      