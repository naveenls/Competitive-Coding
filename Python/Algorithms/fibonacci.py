# -*- coding: utf-8 -*-
"""
Created on Sun Apr  7 10:12:02 2019

@author: HP
"""

import numpy as np

def power(a,n):
    if(n==1):
        return a
    x=power(a,int(n/2))
    if n%2==0:
        return x.dot(x)
    else:
        x=x.dot(x)
        return x.dot(mat)
        
mat=np.array([[1,1],[1,0]])
base=np.array([[1],[1]])

n=int(input('enter a number'))
mat1=power(mat,n-2)
print(mat1)
print(mat1.dot(base)[0][0])