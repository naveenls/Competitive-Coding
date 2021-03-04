# -*- coding: utf-8 -*-
"""
Created on Tue Jun 25 20:32:36 2019

@author: HP
"""

res=[]
res.append(1)
n=100
def update_arr(x):
    carry=0
    for i in range(len(res)-1,-1,-1):
        num=res[i]*x
        num=num+carry
        res[i]=num%10
        carry=int(num/10)
    while carry>0:
        res.insert(0,carry%10)
        carry=int(carry/10)
        
for x in range(1,n+1):
    update_arr(x)

s=''
dic={0:'0',1:'1',2:'2',3:'3',4:'4',5:'5',6:'6',7:'7',8:'8',9:'9'}
for i in res:
    s=s+dic[i]
print(s)