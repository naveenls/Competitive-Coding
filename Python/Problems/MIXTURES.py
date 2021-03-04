# -*- coding: utf-8 -*-
"""
Created on Thu Jun 20 23:58:26 2019

@author: HP
"""
import math
while(1):
    try:
        N=int(input())
    except:
        break
    Sum=[0 for i in range(N+1)]
    A = [int(x) for x in input().split()] 
    for i in range(1,N+1):
        Sum[i]=Sum[i-1]+A[i-1]
    DP=[[math.inf for i in range(N+1)] for i in range(N+1)]
    for l in range(1,N+1):
        for i in range(1,N-l+2):
            j=i+l-1
            if i==j:
                DP[i][j]=0
            else:
                for k in range(i,j):
                    DP[i][j]=min(DP[i][j], DP[i][k] + DP[k+1][j] + ((Sum[k] - Sum[i-1])%100) * ((Sum[j]-Sum[k])%100))
    print(DP[1][N])
