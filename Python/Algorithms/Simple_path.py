# -*- coding: utf-8 -*-
"""
Created on Fri Jun  7 15:24:49 2019

@author: HP
"""

class Node:
    def __init__(self,key):
        self.k=key
        self.path=None
        self.ways=[]
        self.adj=[]
    
    def insert(self,node):
        self.adj.append(node)
        
class Graph:
    def __init__(self):
        self.vertices=[]
        self.edges=[]
    
    def add_edge(self,u,v,weight=None):
        new_edge=[u,v,weight]
        self.edges.append(new_edge)   

gr = { 'a' : ['b','c','d'], 'b' : ['c','d'], 'c' : ['d'], 'd' : [] }

g=Graph()

for key in gr:
    new_node=Node(key)
    g.vertices.append(new_node)
   
for i in g.vertices:
    val=i.k
    for j in gr[val]:
        ind=ord(j)-ord('a')
        i.insert(g.vertices[ind])
        g.add_edge(i,g.vertices[ind])
  
def simple_path(u,v):
    if u==v:
        return 1
    elif u.path!=None:
        return u.path
    else:
        u.path=0
        for w in u.adj:
            c=simple_path(w,v)
            u.path=u.path+c
            if c!=0:
                for way in w.ways:
                    new_way=[]
                    new_way=new_way+way
                    new_way.insert(0,u)
                    u.ways.append(new_way)
        return u.path
    
     
def paths(u,v):
    way=[]
    way.insert(0,v)
    v.ways.append(way)
    d=simple_path(u,v)
    for way in u.ways:
        for node in way:
            print(node.k)
        print(' ')
    return d
    

print(paths(g.vertices[0],g.vertices[3]))
