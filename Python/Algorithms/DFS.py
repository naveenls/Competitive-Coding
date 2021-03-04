# -*- coding: utf-8 -*-
"""
Created on Fri Jun  7 00:05:45 2019

@author: HP
"""

time=0

class Node:
    def __init__(self,key):
        self.k=key
        self.d=0
        self.f=0
        self.parent=None
        self.color="white"
        self.adj=[]
    
    def insert(self,node):
        self.adj.append(node)

g = { 'a' : ['c'], 'b' : ['c', 'e'], 'c' : ['a', 'b', 'd', 'e'], 'd' : ['c'], 'e' : ['c', 'b'], 'f' : [] }

list=[]

for key in g:
    new_node=Node(key)
    list.append(new_node)
   
for i in list:
    val=i.k
    for j in g[val]:
        ind=ord(j)-ord('a')
        i.insert(list[ind])
  
def DFS_Visit(node):
    global time
    time=time+1
    node.d=time
    node.color="gray"
    for j in i.adj:
        if j.color=="white":
            j.parent=node
    time=time+1
    node.color="black"
    node.f=time
    
def DFS():
    for i in list:
        if i.color=="white":
            DFS_Visit(i)
            
DFS()
