# -*- coding: utf-8 -*-
"""
Created on Fri Aug 23 23:03:17 2019

@author: HP
"""

x="kitten"
y="sitting"

def Dist(x,y):
    n=len(x)
    m=len(y)
    DP=[[0 for i in range(0,n+1)] for j in range(0,m+1)]
    for i in range(n+1):
        DP[0][i]=i
    for i in range(m+1):
        DP[i][0]=i
    for i in range(1,m+1):
        for j in range(1,n+1):
            if y[i-1]==x[j-1]:
                DP[i][j]=DP[i-1][j-1]
            else:
                DP[i][j]=min(DP[i-1][j],DP[i][j-1],DP[i-1][j-1])+1
    return DP

print(Dist(x,y))