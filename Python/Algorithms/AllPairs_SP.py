# -*- coding: utf-8 -*-
"""
Created on Thu Jun 20 20:24:53 2019

@author: HP
"""
import math
from copy import deepcopy

n=5

class Graph:
    def __init__(self):
        self.v=[]
        self.e=[]
        
class Node:
    def __init__(self,key):
        self.k=key
        self.d=0
        self.parent=None
        self.adj=[]
    
    def insert(self,node):
        self.adj.append(node)
        
def Extend_Shortes_path(L,W):
    global n
    L1=[[math.inf for i in range(n+1)] for j in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,n+1):
            for k in range(1,n+1):
                L1[i][j]=min(L1[i][j],L[i][k]+W[k][j])
    return L1

def AP_SP(W):
    L=deepcopy(W)
    i=1
    while i<n-1:
        L=Extend_Shortes_path(L,L)
        i=i*2
    return L

def Floyd_warshall(G,W):
    global n
    D=deepcopy(W)
    for k in range(1,n+1):
        D1=[[math.inf for i in range(n+1)] for j in range(n+1)]
        for i in range(1,n+1):
            for j in range(1,n+1):
                D1[i][j]=min(D[i][j],D[i][k]+D[k][j])
                D=deepcopy(D1)
    return D