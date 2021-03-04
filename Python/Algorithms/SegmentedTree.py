# -*- coding: utf-8 -*-
"""
Created on Tue Apr  9 16:57:08 2019

@author: HP
"""

# -*- coding: utf-8 -*-
"""
Created on Sun Apr  7 17:19:11 2019

@author: HP
"""

# -*- coding: utf-8 -*-
"""
Created on Sun Apr  7 16:50:16 2019

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
            new_node.key=arr[l]
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
    
    def PointUpdate(self,node,i,x):
        if node.l==node.r:
            node.key=x
        else:
            mid=int((node.l+node.r)/2);
            if i>=node.l and i<=mid:
                list.PointUpdate(node.left_child,i,x)
                node.key+=(x-arr[i])
            else:
                list.PointUpdate(node.right_child,i,x)
                node.key+=(x-arr[i])
                
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
        
            
    def Print(self,node):
        if node==None:
            return
        print(node.key)
        list.Print(node.left_child)
        list.Print(node.right_child)
            
        
list=SegmentedTree()
arr=[1,2,3,4,5,6,7,8,9]

list.BuildTree(None,0,8,None)
list.PointUpdate(list.root,3,4)
print(list.RangeQuery(list.root,3,7))

list.Print(list.root)
