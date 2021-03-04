# -*- coding: utf-8 -*-
'''
Created on Thu Jun  6 20:48:32 2019

@author: HP
'''

import math

class Node:
    def __init__(self,key):
        self.k=key
        self.d=math.inf
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
        
open_list=[]

def BFS(s):
    open_list.append(s)
    s.color="gray"
    s.d=0
    while(len(open_list)>0):
        node=open_list[0]
        for adj in node.adj:
            if adj.color=="white":
                adj.parent=node
                adj.d=node.d+1
                open_list.append(adj)
                adj.color="gray"
        node.color="black"
        open_list.remove(node)

BFS(list[0])

for i in list:
    print(i.d)
    