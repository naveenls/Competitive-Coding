# -*- coding: utf-8 -*-
"""
Created on Fri Jun 21 21:41:16 2019

@author: HP
"""
def isSubsetSum(set,n,sum): 

    subset=([[False for i in range(sum+1)]  
            for i in range(n+1)]) 
      
    for i in range(n+1): 
        subset[i][0] = True
          
  
        for i in range(1,sum+1): 
            subset[0][i]=False
              
        for i in range(1,n+1): 
            for j in range(1,sum+1): 
                if j<set[i-1]: 
                    subset[i][j] = subset[i-1][j] 
                else:
                    subset[i][j] = (subset[i-1][j] or 
                                   subset[i - 1][j-set[i-1]]) 
      
 
    return subset[n][sum]     

def reverse(A,l,r):
    while(l<=r):
        A[l],A[r]=A[r],A[l]
        l=l+1
        r=r-1

N,Q=[int(x) for x in input().split()] 
C=[int(x) for x in input().split()]
A=[0]
A=A+C 
while(Q):
    B=[int(x) for x in input().split()] 
    if len(B)==4:
        if(isSubsetSum(A[B[1]:B[2]+1],B[2]-B[1]+1,B[3])):
            print("Yes")
        else:
            print("No")
    elif B[0]==1:
        A[B[1]]=B[2]
    else:
        reverse(A,B[1],B[2])
    Q=Q-1