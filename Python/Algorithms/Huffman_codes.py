# -*- coding: utf-8 -*-
"""
Created on Sun May 26 21:20:42 2019

@author: HP
"""

class Node:
    def __init__(self,data,char):
        self.key=data
        self.c=char
        self.left_child=None
        self.right_child=None
        self.parent=None
        
    
C=[['a',45],['b',13],['c',12],['d',16],['e',9],['f',5]]
list=[]

for i in range(len(C)):
    New_node=Node(C[i][1],C[i][0])
    list.append(New_node)
    
while len(list)!=1:
#    for i in range(len(list)):
#        print(list[i].key)
    if len(list)>=2:
        if list[0].key<list[1].key:
            small=list[0]
            sec_small=list[1]
        else:
            small=list[1]
            sec_small=list[0]
        for i in range(2,len(list)):
            if small.key>list[i].key:
                sec_small=small
                small=list[i]
            elif sec_small.key>list[i].key:
                sec_small=list[i]
    New_node=Node(small.key+sec_small.key,None)
    New_node.left_child=small
    New_node.right_child=sec_small
    print(New_node.key,New_node.left_child.key,New_node.right_child.key)
    small.parent=New_node
    sec_small.parent=New_node
    list.append(New_node)
    list.remove(small)
    list.remove(sec_small)
    root=New_node
    
PrintTree(root)

def PrintTree(node):
    if node==None:
        return
    else:   
        PrintTree(node.left_child)
        print(node.key)
        PrintTree(node.right_child)