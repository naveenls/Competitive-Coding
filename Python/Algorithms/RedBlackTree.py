# -*- coding: utf-8 -*-
"""
Created on Sat May 18 06:39:30 2019

@author: HP
"""

class Node:
    def __init__(self,data,color="Red"):
        self.k=data
        self.size=0
        self.col=color
        self.lc=None
        self.rc=None
        self.p=None
        
class Tree:
    def __init__(self):
        self.root=None
        self.nil=Node(None,"Black")
        
    def Insert(self,node,x):
        if self.root==None:
            new_node=Node(x,"Black")
            self.root=new_node
            new_node.lc=self.nil
            new_node.rc=self.nil
            new_node.p=self.nil
            list.size_fixup(new_node)
        else:
            if x>=node.k:
                if node.rc==self.nil:
                    new_node=Node(x)
                    node.rc=new_node
                    new_node.p=node
                    new_node.lc=self.nil
                    new_node.rc=self.nil
                    list.size_fixup(new_node)
                    list.Fixup(new_node)
                else:
                    list.Insert(node.rc,x)
            else:
                if node.lc==self.nil:
                    new_node=Node(x)
                    node.lc=new_node
                    new_node.p=node
                    new_node.lc=self.nil
                    new_node.rc=self.nil
                    list.size_fixup(new_node)
                    list.Fixup(new_node) 
                else:
                    list.Insert(node.lc,x)
            
    def Fixup(self,node):
        while node.p!=self.nil and node.p.col=="Red":
            if node.p==node.p.p.rc:
                y=node.p.p.lc
                if y!=self.nil and y.col=="Red":
                    y.col="Black"
                    node.p.col="Black"
                    node.p.p.col="Red"
                    node=node.p.p
                else:
                    if node.p.rc==node:
                        node.p.col="Black"
                        node.p.p.col="Red"
                        list.left_rotate(node.p.p)
                    else:
                        list.right_rotate(node.p)
                        node.col="Black"
                        node.p.col="Red"
                        list.left_rotate(node.p)
                        node=node.rc
            else:
                y=node.p.p.rc
                if y!=self.nil and y.col=="Red":
                    y.col="Black"
                    node.p.col="Black"
                    node.p.p.col="Red"
                    node=node.p.p
                else:
                    if node.p.lc==node:
                        node.p.col="Black"
                        node.p.p.col="Red"
                        list.right_rotate(node.p.p)
                    else:
                        list.left_rotate(node.p)
                        node.col="Black"
                        node.p.col="Red"
                        list.right_rotate(node)
                        node=node.lc
        
        self.root.col="Black"
            
    def left_rotate(self, x):
        y=x.rc
        y.size=x.size
        x.rc=y.lc
        if y.lc != self.nil:
            y.lc.p = x
        y.p=x.p
        if x.p == self.nil:
            self.root = y
        elif x == x.p.lc:
            x.p.lc = y
        else:
            x.p.rc = y
        x.p=y
        y.lc=x
        x.size=x.lc.size+x.rc.size+1

    def right_rotate(self, x):
        y=x.lc
        y.size=x.size
        x.lc=y.rc
        if y.rc !=self.nil:
            y.rc.p=x
        y.p=x.p
        if x.p==self.nil:
            self.root=y
        elif x==x.p.lc:
            x.p.lc = y
        else:
            x.p.rc = y
        x.p=y
        y.rc=x
        x.size=x.lc.size+x.rc.size+1
       
    def size_fixup(self,x):
        while x!=self.nil:
            x.size=x.size+1
            x=x.p
    
    def OS_select(self,x,i):
        r=x.lc.size+1
        if i==r:
            return x
        elif i<r:
            return list.OS_select(x.lc,i)
        else:
            return list.OS_select(x.rc,i-r)
        
    def OS_rank(self,x):
        r=x.lc.size+1
        y=x
        while y!=self.root:
            if y==y.p.rc:
                r=r+y.p.lc.size+1
            y=y.p
        return r
       
    def OS_key_rank(self,node,x):
        if node.k==x:
            return node.lc.size+1
        elif node.k>x:
            return self.OS_key_rank(node.lc,x)
        else:
            return node.lc.size+1+self.OS_key_rank(node.rc,x)
        
    def InorderPrint(self,node):
        if node==self.nil:
            return
        list.InorderPrint(node.lc)
        print(node.k,node.col,node.size)
        list.InorderPrint(node.rc)  
               
list=Tree()
for i in range(1,8):
    list.Insert(list.root,i)
list.InorderPrint(list.root)
