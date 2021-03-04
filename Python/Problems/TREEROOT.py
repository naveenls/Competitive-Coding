# -*- coding: utf-8 -*-
"""
Created on Fri Jun 21 20:10:10 2019

@author: HP
"""
def sortSecond(val): 
    return val[1]  

T=int(input())
while(T):
    N=int(input())
    A=[]
    x=0
    for i in range(N):
        new = [int(x) for x in input().split()] 
        A.append(new)
        x=x+new[0]-new[1]
    for a in A:
        if x==a[0]:
            print(x)
            break
    T=T-1