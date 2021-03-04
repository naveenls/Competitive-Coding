# -*- coding: utf-8 -*-
"""
Created on Mon Jun 10 22:57:57 2019

@author: HP
"""
import math

T=int(input())
while(T):
    N=int(input())
    A = [int(x) for x in input().split()] 
    fac=[0 for i in range(1000001)]
    prod=1
    for i in range(N):
        x=int(A[i])
        for i in range(2,int(math.sqrt(x))+1,2):
            if(x==1):
                break
            else:
                while(x%i==0):
                    x=x/i
                    fac[i]=fac[i]+1
        if x>=2:
            fac[x]=fac[x]+1
    for i in range(10):
        prod=prod*(fac[i]+1)
    print(prod)
    T=T-1