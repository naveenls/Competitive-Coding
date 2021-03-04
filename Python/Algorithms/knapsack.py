# -*- coding: utf-8 -*-
"""
Created on Sun May 26 16:37:56 2019

@author: HP
"""

def knapsack(p,W,n):
    c = [[0 for x in range(W+1)] for y in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,W+1):
            if j<p[i][1]:
                c[i][j]=c[i-1][j]
            else:
                c[i][j]=max(c[i-1][j],c[i-1][j-p[i][1]]+p[i][0])
    return c[n][W]

p=[[0,0],[60,10],[100,20],[120,30]]
print(knapsack(p,50,3))