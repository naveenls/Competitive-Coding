# -*- coding: utf-8 -*-
"""
Created on Sun Apr  7 16:50:16 2019

@author: HP
"""
class Node:
    def __init__(self,data):
        self.key=data
        self.next=None
        
class LinkedList:
    
    def __init__(self):
        self.head=None
        self.tail=None
        
    def push(self,data):
        new_node=Node(data)
        new_node.next=self.head
        self.head=new_node
        if self.tail==None:
            self.tail=self.head
            
    def pop(self):
        if self.head!=None:
            self.head=self.head.next
        
    def prnt(self,node):
        while node!=None:
            print(node.key)
            node=node.next
        
list=LinkedList()
list.push(5)
list.push(10)
list.push(9)
list.push(13)
list.pop()

list.prnt(list.head)

print(list.head.key,list.tail.key)