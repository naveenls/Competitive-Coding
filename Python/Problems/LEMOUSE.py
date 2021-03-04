# -*- coding: utf-8 -*-
"""
Created on Sat Jun 22 00:22:04 2019

@author: HP
"""

T=int(input())
while(T):
    n,m=[int(x) for x in input().split()] 
    A=[]
    for i in range(n):
        B=[int(x) for x in input().split()]
        A.append(B)
    DP=[[0 for i in range(m)] for j in range(n)]          
    for i in range(m):
        if i<m-1:
            DP[0][i]=DP[0][i-1]+A[1][i]+A[0][i+1]
        else:
            DP[0][i]=DP[0][i-1]+A[1][i]
            
    for i in range(n):
        if i<n-1:
            DP[i][0]=DP[i-1][0]+A[i+1][0]+A[i][1]
        else:
            DP[i][0]=DP[i-1][0]+A[i][1]
            
    for i in range(1,n):
        for j in range(1,m):
            if i<n-1 and j<m-1:
                DP[i][j]=min(DP[i-1][j],DP[i][j-1])+A[i+1][j]+A[i][j+1]
            elif i<n-1:
                DP[i][j]=min(DP[i-1][j],DP[i][j-1])+A[i+1][j]
            elif j<m-1:
                DP[i][j]=min(DP[i-1][j],DP[i][j-1])+A[i][j+1]
            else:
                DP[i][j]=min(DP[i-1][j],DP[i][j-1])
    print(DP)
    T=T-1