# -*- coding: utf-8 -*-
"""
Created on Tue Jun 25 15:56:45 2019

@author: HP
"""

import random

def power(a,n,p):
    res=1
    while n>0:
        if n%2==1:
            res=(res*a)%p
        n=n/2
        res=(res*res)%p
    return res

def euclidean_gcd(a,b):
    if b==0:
        return a
    else:
        return euclidean_gcd(a,a%b)
        
def fermat(n,k):
    while k>0:
        a=random.randrange(2,n-1)
        if euclidean_gcd(n,a)!=1:
            return False
        if power(a,n-1,n)!=1:
            return False
        k=k-1
    return True

def Miller_Rabin_Exd(a,d,n):
    x=power(a,d,n)
    if x==1 or x==n-1:
        return True
    while d<n-1:
        x=(x*x)%n
        d=d*2
        if x==1:
            return False
        else:
            return True
        
def Miller_Rabin(n,k):
    if n%2==0:
        return False
    t=n-1
    d=0
    s=0
    while t%2==0:
        s=s+1
        t=t/2
    d=t
    while k>0:
        a=random.randrange(2,n-1)
        x=Miller_Rabin_Exd(a,d,n)
        if x==False:
            return False
    return True