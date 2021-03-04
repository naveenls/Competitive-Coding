# -*- coding: utf-8 -*-
"""
Created on Tue Jun 25 21:35:01 2019

@author: HP
"""

import math

T=int(input())
while(T):
    N=int(input())
    s=0
    if N==1:
        print(1)
    else:
        n=int((math.sqrt(1+8*N)-1)/2)
        k=(n*(n+1))/2
        k1=((n+1)*(n+2))/2
        if N-k<=k1-N:
            s=n+N-k
        else:
            s=n+1
            s=s+k1-N
        print(int(s))
    T=T-1   