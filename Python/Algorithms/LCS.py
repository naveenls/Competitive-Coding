# -*- coding: utf-8 -*-
"""
Created on Mon May 20 23:01:44 2019

@author: HP
"""

x="0ABCBDA"
y="0BDCABA"

def LCS(x,y):
    m=len(x)-1
    n=len(y)-1
    c=[[0 for i in range(0,n+1)] for j in range(0,m+1)]
    b=[[0 for i in range(0,n+1)] for j in range(0,m+1)]    
    for i in range(1,m+1):
        for j in range(1,n+1):
            if x[i]==y[j]:
                c[i][j]=c[i-1][j-1]+1
                b[i][j]=[-1,-1]
            else:
                if c[i-1][j]>=c[i][j-1]:
                    c[i][j]=c[i-1][j]
                    b[i][j]=[-1,0]
                else:
                    c[i][j]=c[i][j-1]
                    b[i][j]=[0,-1]
    return c,b

# i not equal to j for longest common repeating subsequence of a string
#no of insertions a deletions to make anther string from given string |x|-LCS(x,y)
def print_seq(c,b,i,j):
    if i==0 or j==0:
        return 
    elif b[i][j][0]==b[i][j][1]:
        print_seq(c,b,i+b[i][j][0],j+b[i][j][1])
        print(x[i])
    else:
        print_seq(c,b,i+b[i][j][0],j+b[i][j][1])

c,b=LCS(x,y)
print_seq(c,b,6,6)