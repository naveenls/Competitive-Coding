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
#class Node1:
#    def __init__(self,data):
#        self.key=data
#        self.next=None
#        
class Node:
    def __init__(self,data):
        self.key=data
        self.left_child=None
        self.right_child=None
        
#class LinkedList:
#    
#    def __init__(self):
#        self.head=None
#        self.len=0
#        
#    def push(self,data):
#        new_node=Node1(data)
#        self.len+=1
#        new_node.next=self.head
#        self.head=new_node
#            
#    def pop(self):
#        if self.head!=None:
#            self.len-=1
#            self.head=self.head.next
        
class Tree:
    
    def __init__(self):
        self.root=None
        
    def BuildTree(self,node,i,c):
        new_node=Node(arr[i])
        if self.root==None:
            self.root=new_node
            if c=='l':
                node.left_child=new_node
            elif c=='r':
                node.right_child=new_node 
        else:
            new_node=Node(arr[i])
            if c=='l':
                node.left_child=new_node
            elif c=='r':
                node.right_child=new_node 
                
        if 2*i+1<len(arr):
            list.BuildTree(new_node,2*i+1,'l')
        if 2*i+2<len(arr):
            list.BuildTree(new_node,2*i+2,'r')
            
    def Print(self,node):
        if node==None:
            return
        print(node.key)
        list.Print(node.left_child)
        list.Print(node.right_child)
            
        
list=Tree()
arr=[1,2,3,4,5,6,7,8,9]

list.BuildTree(None,0,None)

#lst=LinkedList()
#lst.push(list.root)
#while lst.len!=0:
#    print(lst.head.key.key)
#    node=lst.head
#    lst.pop()
#    if node.key.right_child!=None:
#        lst.push(node.key.right_child)
#    if node.key.left_child!=None:
#        lst.push(node.key.left_child)

list.Print(list.root)
