# -*- coding: utf-8 -*-
"""
Created on Sat Jun 22 21:32:15 2019

@author: HP
"""

T=int(input())
while(T):
    N=int(input())
    A=input()
    sum=0
    for i in range(N):
        if int(A[i])==1:
            k=0
            for j in range(i,N):
                if int(A[j])==1:
                    k=k+1
            sum=sum+k
    print(sum)
    T=T-1   