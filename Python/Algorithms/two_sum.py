# -*- coding: utf-8 -*-
"""
Created on Fri Aug 23 23:30:14 2019

@author: HP
"""
#dividing array into two arrays of equal sums
#can be done by using DP
s1=[]
s2=[]
def two_sum(arr,i,sum1):
    if i==0:
        if (arr[i]==sum1):
            s1.append(arr[i])
            return 1
        elif sum1==0:
            s2.append(arr[i])
            return 1
        else:
            return 0
    elif sum1<0:
        return 0
    else:
        if two_sum(arr,i-1,sum1-arr[i]):
            s1.append(arr[i])
            return 1
        elif two_sum(arr,i-1,sum1):
            s2.append(arr[i])
            return 1
        else:
            return 0
  
arr=[3,1,1,2,2,1,6]
sum=0
for i in arr:
    sum+=i
sum=int(sum/2)
print(two_sum(arr,len(arr)-1,sum))
for i in s1:
    print(i,end=" ")
print()
for i in s2:
    print(i,end=" ")