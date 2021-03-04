# -*- coding: utf-8 -*-
"""
Created on Mon May 27 22:12:22 2019

@author: HP
"""
import math
import heapq


n,k=input().split()

n=int(n)
k=int(k)

A = [int(x) for x in input().split()] 
C=[]

for i in range(1,n):
    small=math.inf
    for j in range(i-k,i):
        if j>=0:
            if C[j]<small:
                small=C[j]
    C.append(small*A[i])
    
print(C[n-1]%(1000000007))