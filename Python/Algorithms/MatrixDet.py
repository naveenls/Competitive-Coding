# -*- coding: utf-8 -*-
"""
Created on Thu Apr 18 10:07:06 2019

@author: HP
"""
import math

def Det(x,n):
    if len(x[0])==1:
        return x[0][0]
    else:
        sum=0
        for i in range(n):
            sum+=math.pow(1,i)*x[0][i]*Det(x[1:n,[j for j in range(n) if j!=i]],n-1)
        return sum
    
x=[[1,2,3],[4,5,6],[7,8,9]]
print(Det(x,3))