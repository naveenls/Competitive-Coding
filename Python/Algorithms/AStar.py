# -*- coding: utf-8 -*-
"""
Created on Mon Apr 15 16:55:08 2019

@author: HP
"""
import math
import cv2
def neighbours(node):
    dstns=[[1,0],[-1,0],[0,1],[0,-1],[1,1],[1,-1],[-1,-1],[-1,1]]
    result=[]
    for dstn in dstns:
        neighbour=[node[0]+dstn[0],node[1]+dstn[1]]
        if neighbour not in all_nodes:
            result.append(neighbour)
    return result

class Node:
    def __init__(self,Parent=None,Position=None):
        self.parent=Parent
        self.position=Position
        self.g=0
        self.h=0
        self.f=0

def astar(all_nodes,start,end):
    path=[]
    open_list=[]
    closed_list=[]
    start_node=Node(None,start)
    start_node.g=start_node.h=start_node.f=0
    open_list.append(start_node)
    
    while len(open_list)>0:
        curr_node=open_list[0]
        curr_ind=0
        for index,node in enumerate(open_list):
            if node.f<curr_node.f:
                curr_node=node
                curr_ind=index
        open_list.pop(curr_ind)
        closed_list.append(curr_node)
        if curr_node.position==end:
            current=curr_node
            while current.parent!=None:
                path=[current.position] + path
                current=current.parent
            path=[current.position] + path
            return path
        
        children=[]
        for result in neighbours(curr_node.position):
            new_node=Node(curr_node,result)
            if new_node in closed_list:
                continue
            new_node.g=curr_node.g+math.sqrt(abs(result[0]-curr_node.position[0])+abs(result[1]-curr_node.position[1]))
            new_node.h=abs(end[0]-result[0])+abs(end[1]-result[1])
            new_node.f=new_node.g+new_node.h
            children.append(new_node)
        
        for child in children:
            for open_node in open_list:
                if child.position==open_node.position and child.g>open_node.g:
                    continue
            open_list.append(child)
            
all_nodes=[]

img = cv2.imread(r'F:\CS Projects\Coding\Python\Input\maze.jpg')
rows,cols,h=img.shape
imggray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
blurred = cv2.GaussianBlur(imggray, (5, 5), 0)
ret,thresh = cv2.threshold(blurred,200,255,cv2.THRESH_BINARY)

for i in range(rows):
    for j in range(cols):
        if thresh[i,j]==0:
            all_nodes.append([i,j])

#print(all_nodes)
path=astar(all_nodes,[30,13],[23,158])
print(path)
for node in path:
    cv2.circle(img,(node[1],node[0]), 1, (0,0,255), -1)
cv2.imshow('frame',img)
cv2.imshow('frame1',thresh)
cv2.waitKey()
cv2.destroyAllWindows()
