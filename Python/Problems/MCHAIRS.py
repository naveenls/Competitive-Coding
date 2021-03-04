# -*- coding: utf-8 -*-
"""
Created on Tue Jun 25 23:51:36 2019

@author: HP
"""
p=1000000007

def power(a,b):
    global p
    res=1
    if b%2==0:
        res=(a*a)
        b=b/2
    else:
        res=a
        b=b-1
    while b>1:
        if b%2==1:
            res=(res*a)%p
        res=(res*res)%p
        b=int(b/2)
    return res
T=int(input())
while(T):
    N=int(input())
    x=power(2,N)
    if x==0:
        print(p-1)
    else:
        print(x-1)
    T=T-1   