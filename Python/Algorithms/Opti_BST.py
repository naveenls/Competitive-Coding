# -*- coding: utf-8 -*-
"""
Created on Tue May 21 17:05:21 2019

@author: HP
"""

import math

class Node:
    def __init__(self,data):
        self.key=data
        self.left_child=None
        self.right_child=None
        self.parent=None

class Tree:
    
    def __init__(self):
        self.root=None
        
    def Insert(self,node,x):
        if self.root==None:
            new_node=Node(x)
            self.root=new_node
            self.parent=None
        else:
            if x>=node.key:
                if node.right_child==None:
                    new_node=Node(x)
                    node.right_child=new_node
                    new_node.parent=node
                else:
                    list.Insert(node.right_child,x)
            else:
                if node.left_child==None:
                    new_node=Node(x)
                    node.left_child=new_node
                    new_node.parent=node
                else:
                    list.Insert(node.left_child,x)
    

def Opt_BST(n,p,q):
    c=[[0 for i in range(0,n+1)] for j in range(0,n+2)]
    s=[[0 for i in range(0,n+1)] for j in range(0,n+1)]
    w=[[0 for i in range(0,n+1)] for j in range(0,n+2)]
    for i in range(1,n+2):
        j=i-1
        c[i][j]=q[i-1]
        w[i][j]=q[i-1]
    for l in range(1,n+1):
        for i in range(1,n-l+2):
            j=i+l-1
            w[i][j] = w[i][j-1] + q[i] + p[i]
            min=math.inf
            for k in range(i,j+1):
                r=c[i][k-1]+c[k+1][j]+w[i][j]
                if min>r:
                    s[i][j]=k
                    min=r
            c[i][j]=min
    return c,w

def BuildTree(s,list,i,j):
    if i>=j:
        list.Insert(list.root,s[i][j])
        BuildTree(s,list,i,s[i][j]-1)
        BuildTree(s,list,s[i][j]+1,j)
    
p=[0,0.15,0.10,0.05,0.10,0.20]
q=[0.05,0.10,0.05,0.05,0.05,0.10]

print(Opt_BST(5,p,q))

