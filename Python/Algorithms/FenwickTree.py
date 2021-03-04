# -*- coding: utf-8 -*-
"""
Created on Tue Apr  9 19:25:18 2019

@author: HP
"""
n=10

BITS=[0]*(n+1)
def FenwickTree():
    for i in range(1,n+1):
        j=i & -i
        while j:
            BITS[i]+=arr[i-j]
            j-=1

def UpdateBit(i,x):
    i+=1
    while i<=n:
        BITS[i]+=i
        i+= i & -i
        
def GetSum(i):
    i+=1
    sum=0
    while i>0:
        sum+=BITS[i]
        i-=i & -i
    return sum

arr=[1,2,3,4,5,6,7,8,9,10]

FenwickTree()
UpdateBit(2,3)
print(BITS)
print(GetSum(4))