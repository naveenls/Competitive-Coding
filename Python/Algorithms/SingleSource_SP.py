# -*- coding: utf-8 -*-
"""
Created on Tue Jun 18 18:35:33 2019

@author: HP
"""
import math
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
        
def Relax(e):
    u=e[0]
    v=e[1]
    w=e[2]
    if v.d>u.d+w:
        v.d=u.d+w
        v.parent=u
 
def Initialize(G,s):
    for v in G.v:
        v.d=math.inf
        v.p=None
        
def Bellman_Ford(G,s):
    Initialize(G,s)
    for i in range(len(G.v)):
        for e in G.e:
            Relax(e)
    for e in G.e:
        if e[1].d>e[0].d+e[2]:
            return False
    return True

def Find_edge(G,u,v):
    for e in G.e:
        if e[0]==u and e[1]==v:
            return e
    return None

def Dag_Shortest_path(G,s):
    sort=Topological_Sort(G)
    Initialize(G,s)
    for v in sort:
        for u in v.adj:
            e=Find_edge(G,u,v)
            Relax(e)
    
def Dijikstra(G,s):
    Initialize(G,s)
    s=[]
    Q=G.v
    while len(Q)>0:
        u=Extract_Min(Q)
        s.append(u)
        for v in u.adj:
            e=Find_edge(G,u,v)
            Relax(e)

    