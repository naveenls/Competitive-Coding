# -*- coding: utf-8 -*-
"""
Created on Fri Aug 23 16:42:14 2019

@author: HP
"""
x="ABCDE"
y="FABCD"
max=[0,0,0]
def LCSub(x,y):
    global max
    n=len(x)
    DP=[[0 for i in range(0,n+1)] for j in range(0,n+1)]
    for i in range(n+1):
        DP[0][i]=DP[i][0]=0
    for i in range(1,n+1):
        for j in range(1,n+1):
            if x[i-1]==y[j-1]:
                DP[i][j]=DP[i-1][j-1]+1
                if DP[i][j]>max[0]:
                    max=[DP[i][j],i,j]
            else:
                DP[i][j]=0
    print(DP,max)
    
LCSub(x,y)