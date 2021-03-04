# -*- coding: utf-8 -*-
"""
Created on Sat Jun 22 17:32:26 2019

@author: HP
"""
class Node:
    key=0
    l=0
    r=0
    def __init__(self):
        self.left_child=None
        self.right_child=None
        
        
class SegmentedTree:
    
    def __init__(self):
        self.root=None
        
    def BuildTree(self,node,l,r,c):
        new_node=Node()
        
        if node==None:
            self.root=new_node
        if c=='l':
            node.left_child=new_node
        elif c=='r':
            node.right_child=new_node
            
        if l==r:
            new_node.key=0
            new_node.l=l
            new_node.r=l
            
        else:
            mid=int((l+r)/2);
            left=list.BuildTree(new_node,l,mid,'l')
            right=list.BuildTree(new_node,mid+1,r,'r')
            new_node.key=left+right
            new_node.l=l
            new_node.r=r
            
        return new_node.key
    
    def PointUpdate(self,node,i):
        if node.l==node.r:
            node.key=1-node.key
            arr[i]=1-arr[i]
        else:
            mid=int((node.l+node.r)/2);
            if i>=node.l and i<=mid:
                if arr[i]==1:
                    node.key+=-1
                else:
                    node.key+=1
                list.PointUpdate(node.left_child,i)
            else:
                if arr[i]==1:
                    node.key+=-1
                else:
                    node.key+=1
                list.PointUpdate(node.right_child,i)
                
    def RangeQuery(self,node,l,r):
        if node.r<l or node.l>r:
            return 0
        elif node.l>=l and node.r<=r:
            return node.key
        else:
            mid=int((node.l+node.r)/2);
            p1=list.RangeQuery(node.left_child,l,mid)
            p2=list.RangeQuery(node.right_child,mid+1,r)
            return p1+p2

        
list=SegmentedTree()
N,Q = [int(x) for x in input().split()] 
arr=[0 for i in range(N)]
list.BuildTree(None,0,N-1,None)
while(Q):
    A=[int(x) for x in input().split()] 
    if A[0]==0:
        for i in range(A[1],A[2]+1):
            list.PointUpdate(list.root,i)
    else:
        print(list.RangeQuery(list.root,A[1],A[2]))
    Q=Q-1
    