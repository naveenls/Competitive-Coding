# -*- coding: utf-8 -*-
"""
Created on Sun Apr  7 17:19:11 2019

@author: HP
"""

   
class Node:
    def __init__(self,data):
        self.key=data
        self.left_child=None
        self.right_child=None
        self.parent=None

class Tree:
    
    def __init__(self):
        self.root=None
        self.min=None
        self.max=None
        
    def Insert(self,node,x):
        if self.root==None:
            new_node=Node(x)
            self.root=new_node
            self.parent=None
            self.max=new_node
            self.min=new_node
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
            list.Update()
    
    def Delete(self,x):
        nd=list.Search(self.root,x)
        if nd.left_child==None and nd.right_child==None:
            if nd.parent.left_child==nd:
                nd.parent.left_child=None
            else:
                nd.parent.right_child=None
        elif nd.left_child==None:
            if nd.parent.left_child==nd:
                nd.parent.left_child=nd.right_child
                nd.right_child.parent=nd.parent
            else:
                nd.parent.right_child=nd.right_child
                nd.right_child.parent=nd.parent
        elif nd.right_child==None:
            if nd.parent.left_child==nd:
                nd.parent.left_child=nd.left_child
                nd.left_child.parent=nd.parent
            else:
                nd.parent.right_child=nd.left_child
                nd.left_child.parent=nd.parent
        else:
            node=nd.right_child
            while node.left_child!=None:
                node=node.left_child
            if node!=nd.right_child:
                nd.key=node.key
                node.parent.left_child=node.right_child
                node.right_child.parent=nd.parent
            else:
                nd.key=node.key
                nd.right_child=node.right_child
                if node.right_child!=None:
                    node.right_child.parent=nd
            
    def Update(self):
        if self.min.left_child is not None:
            self.min=self.min.left_child
        if self.max.right_child is not None:
            self.max=self.max.right_child

    def Search(self,node,x):
        
        if node==None:
            return None
        else:
            if x==node.key:
                return node
            elif x>node.key:
                return list.Search(node.right_child,x)
            else:
                return list.Search(node.left_child,x)
        
    def InorderPrint(self,node):
        if node==None:
            return
        list.InorderPrint(node.left_child)
        print(node.key)
        list.InorderPrint(node.right_child)
        
            
        
list=Tree()
arr=[1,3,14,12,13,2,11,8,9]

list.Insert(list.root,10)

for i in arr:
    list.Insert(list.root,i)    
#list.Delete(14)
#list.Delete(13)
#list.Delete(8)
#list.Delete(9)
#list.Delete(1)
#list.Delete(3)
list.InorderPrint(list.root)
