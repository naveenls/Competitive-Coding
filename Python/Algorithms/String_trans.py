# -*- coding: utf-8 -*-
"""
Created on Tue May 21 22:46:37 2019

@author: HP
"""

import math
cost={'C':1,'R':4,'D':4,'I':5,'T':1.5,'K':0}

def string_trans(x,y,i,j):
    n=len(x)
    m=len(y)
    if i==n:
        return (m-j)*cost['I']
    if j==m:
        return min(cost['K'],(n-1)*cost['D'])
    if x[i]==y[j]:
        c1=cost['C']+string_trans(x,y,i+1,j+1)
    else:
        c1=math.inf
    c2=cost['R']+string_trans(x,y,i+1,j+1)
    c3=cost['D']+string_trans(x,y,i+1,j)
    c4=cost['I']+string_trans(x,y,i,j+1)
    if i<n-1 and j<m-1:
        if x[i]==y[j+1] and x[i+1]==y[j]:
            c5=cost['T']+string_trans(x,y,i+2,j+2)
        else:
            c5=math.inf
    else:
        c5=math.inf
    
    return min(c1,c2,c3,c4,c5)

x="algorithm"
y="algorithm"

print(string_trans(x,y,0,0))