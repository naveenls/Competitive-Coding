# -*- coding: utf-8 -*-
"""
Created on Sun Apr  7 11:13:03 2019

@author: HP
"""
def middle_element(x):
    return int(len(x)/2)
def merge_tuple(a,b):
    c = []
    while len(a) != 0 and len(b) != 0:
        if a[0][0] < b[0][0]:
            c.append(a[0])
            a.remove(a[0])
        else:
            c.append(b[0])
            b.remove(b[0])
    if len(a) == 0:
        c += b
    else:
        c += a
    return c

def mergesort_tuple(x):
    if len(x) == 0 or len(x) == 1:
        return x
    else:
        middle = int(len(x)/2)
        a = mergesort_tuple(x[:middle])
        b = mergesort_tuple(x[middle:])
        return merge_tuple(a,b)

def lol(x,k):
    return [x[i:i+k] for i in range(0,len(x),k)]

def preprocess(x):
    return list(zip(x,range(len(x))))


def ChoosePivot(x):
    if len(x) <= 5 and len(x)!=0:
        return mergesort_tuple(x)[middle_element(x)]
    elif len(x)!=0:
        lst = lol(x,5)
        lst = [mergesort_tuple(el) for el in lst]
        C = [el[middle_element(el)] for el in lst]
        return ChoosePivot(C)
    
def partition(x,index):
    x[len(x)-1],x[index]=x[index],x[len(x)-1]
    i=-1
    key=x[len(x)-1]
    for j in range(0,len(x)-2):
        if x[j]<key:
            i+=1
            x[j],x[i]=x[i],x[j]
    x[len(x)-1]=x[i+1]
    x[i+1]=key
    return x,i+1



def dselect(x,k):
    if len(x)==1:
        return x[0]
    else:
        t=preprocess(x)
        #print(t)
        c=ChoosePivot(t)
    
        x1,p=partition(x,c[1])
        print(x1,p,k)
        if p==k:
            return x1[p]
        elif p>k:
            dselect(x1[:p],k)
        elif p<k:
            dselect(x1[p+1:],k-p-1)
            

arr=[1,6,5,3,2,9,8,10,7,4]
r=dselect(arr,3)
print(r)