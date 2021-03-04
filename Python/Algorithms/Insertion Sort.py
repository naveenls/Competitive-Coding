# -*- coding: utf-8 -*-
"""
Created on Sun Apr  7 09:39:43 2019

@author: HP
"""
def swap(a,b):
    temp=arr[a]
    arr[a]=arr[b]
    arr[b]=temp

def InsertionSort():
    for i in range(1,len(arr)):
        j=i
        while(arr[j-1]>arr[j] and j-1>=0):
            swap(j-1,j)
            j=j-1
            
arr=[5,7,8,2,1,7,10,13]
InsertionSort()
print(arr)