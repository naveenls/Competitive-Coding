# -*- coding: utf-8 -*-
"""
Created on Tue Jun 25 17:23:19 2019

@author: HP
"""
def Extended_Euclidean(a,b):
    if b==0:
        return 1,0,a
    else:
        m,n,gcd1=Extended_Euclidean(b,a%b)
        x=n
        y=m-int(a/b)*n
        gcd=gcd1
        return x,y,gcd
    
print(Extended_Euclidean(10,7))