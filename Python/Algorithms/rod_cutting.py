# -*- coding: utf-8 -*-
"""
Created on Mon May 20 11:12:01 2019

@author: HP
"""

r=[]
s=[]
c=3

def rod_cutting(n,p):
    r.append(0)
    for i in range(1,n+1):
        q=-5
        ind=i
        for j in range(1,i+1):
            if q<(p[j]+r[i-j]):
                ind=j
                q=p[j]+r[i-j]
                s.insert(i,j)
        if ind!=i:
            r.append(q-c)
        else:
            r.append(q)
    return r[n]

p=[0,1,5,8,9,10,17,17,20,24,30]
print(rod_cutting(5,p))
n=5
while n>0:
    print(s[n])
    n=n-s[n]