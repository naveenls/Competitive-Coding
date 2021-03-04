# -*- coding: utf-8 -*-
"""
Created on Mon May 20 17:32:35 2019

@author: HP
"""
import math
import numpy as np

n=11
c = [[0 for x in range(n)] for y in range(n)] 
s = [[0 for x in range(n)] for y in range(n)] 
Ar=[]

def mat_prod(a,b):
    np.matmul(a,b)

def mat_chain(n,A):
    for l in range(2,n+1):
        for i in range(1,n-l+2):
            j=i+l-1
            q=math.inf
            for k in range(i,j):
                r=c[i][k]+c[k+1][j]+A[i-1]*A[k]*A[j]
                if r<q:
                    ind=k
                    q=r
            c[i][j]=q
            s[i][j]=ind
    return c[1][n]

def find_prod(s,i,j):
    if i==j:
        return Ar[j]
    else:
        return mat_prod(find_prod(s,i,s[i][j]),find_prod(s,s[i][j]+1,j))

for i in range(1,n+1):
    m=np.zeros(5,5)
    Ar.insert(i,m)

A=[30,35,15,5,10,20,25]
print(mat_chain(6,A))
