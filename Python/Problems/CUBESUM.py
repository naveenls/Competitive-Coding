# -*- coding: utf-8 -*-
"""
Created on Fri Jun 28 20:19:02 2019

@author: HP
"""

T=int(input())
while(T):
    X,Y,Z=[int(x) for x in input().split()]
    A=[[[0 for i in range(Z)] for j in range(Y)] for k in range(X)]
    B=[[[0 for i in range(Z+1)] for j in range(Y+1)] for k in range(X+1)]
    for i in range(1,X+1):
        for j in range(1,Y+1):
            B[i][j]=[int(x) for x in input().split()]
            B[i][j].insert(0,0)
    for i in range(X,0,-1):
        for j in range(Y,0,-1):
            for k in range(Z,0,-1):
                if i>1 and j>1 and k>1:
                    A[i-1][j-1][k-1]=B[i][j][k]-B[i-1][j][k]-B[i][j-1][k]-B[i][j][k-1]+2*B[i-1][j-1][k-1]
                elif i==1:
                    A[i-1][j-1][k-1]=B[i][j][k]-B[i][j-1][k]-B[i][j][k-1]+B[i][j-1][k-1]
                elif j==1:
                    A[i-1][j-1][k-1]=B[i][j][k]-B[i-1][j][k]-B[i][j][k-1]+B[i-1][j][k-1]
                elif k==1:
                    A[i-1][j-1][k-1]=B[i][j][k]-B[i-1][j][k]-B[i][j-1][k]+B[i-1][j-1][k]
    for i in range(X):
        for j in range(Y):
            print(*(A[i][j][k] for k in range(Z)))
    T=T-1