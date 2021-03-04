# -*- coding: utf-8 -*-
"""
Created on Tue Jun 25 22:53:28 2019

@author: HP
"""
import math
DP=[None for i in range(100001)]
DP[1]=1

def sum_odd(n):
    res=1
    t=n
    while t%2==0:
        t=int(t/2)
    if DP[t]!=None:
        DP[n]=DP[t]
        return
    else:
        for i in range(3,int(math.sqrt(t)+1),2):
            curr_sum=1
            curr_term=1
            while t%i==0:
                curr_term=curr_term*i
                curr_sum=curr_sum+curr_term
                t=int(t/i)
            res=res*curr_sum
        if t>=2:
            res=res*(t+1)
        DP[n]=res
T=int(input())
while(T):
    l,r=[int(x) for x in input().split()]
    sum=0
    for i in range(l,r+1):
        if DP[i]!=None:
            sum=sum+DP[i]
        else:
            sum_odd(i)
            sum=sum+DP[i]
    print(sum)
    T=T-1