# -*- coding: utf-8 -*-
"""
Created on Sun Aug 11 17:58:38 2019

@author: HP
"""
import math
from tkinter import *
from tkinter import ttk

total_length=20

def text_justify(words):
    n=len(words)
    V=[0 for i in range(n)]
    V[0]=len(words[0])
    for i in range(1,n):
        V[i]=V[i-1]+len(words[i])
    DP=[[0 for i in range(n)] for j in range(n)]
    DP1=[[math.inf,0] for i in range(n)]
    for i in range(n):
        for j in range(i,n):
            sum=0
            if i>0:
                sum=total_length-(V[j]-V[i-1])-(j-i)
            else:
                sum=total_length-V[j]-j
            if sum<0:
                DP[i][j]=math.inf
            else:
                DP[i][j]=math.pow(sum,3)
                
    for i in range(n-1,-1,-1):
        for j in range(i,n):
            try:
                if DP1[i][0]>DP[i][j]+DP1[j+1][0]:
                    DP1[i][0]=DP[i][j]+DP1[j+1][0]
                    DP1[i][1]=j+1
            except:
                if DP1[i][0]>DP[i][j]:
                    DP1[i][0]=DP[i][j]
                    DP1[i][1]=j+1
    return(DP1,V)
    
class work_frame:
    global total_length
    def __init__(self,master):
        self.frame=Frame(master)
        self.middleframe=Frame(self.frame,pady=6)
        self.bottomframe=Frame(self.frame)

        self.textbar=Text(self.middleframe,height=8,spacing2=1,width=total_length)
        self.textbar.grid(row=0,column=0)
        
        self.textbar_match=Text(self.middleframe,height=8,spacing2=1,width=total_length)
        self.textbar_match.grid(row=0,column=1)
        
        self.search=Button(self.bottomframe,text="Justify",command=self.justify,padx=50)
        self.clear=Button(self.bottomframe,text="Clear",command=self.clear,padx=50)
        
        self.search.grid(row=0,column=0)
        self.clear.grid(row=0,column=1)
        
        self.middleframe.pack()
        self.bottomframe.pack(side=BOTTOM)
        
    def justify(self):
        self.textbar_match.delete('1.0', END)
        input=self.textbar.get('1.0', END)
        self.words=[]
        i=0
        j=0
        for char in input:
            if char==' ' or char=='\n':
                new_word=input[i:j]
                self.words.append(new_word)
                print(new_word)
                i=j+1
                j=i
            else:
                j=j+1
        try:
            DP,V=text_justify(self.words)
            i=0
            while(i<len(self.words)):
                j=DP[i][1]
                le=0
                if i>0:
                    le=V[j-1]-V[i-1]
                else:
                    le=V[j-1]
                th=int((total_length-le)/(j-i-1))
                space=''
                for j in range(th):
                    space=space+' '
                    
                for word in self.words[i:j-1]:
                    self.textbar_match.insert(INSERT,word+space)
                self.textbar_match.insert(INSERT,self.words[j-1]+'\n')
                i=j
        except:
            print("No input given")
                
    def clear(self):
        self.textbar.delete('1.0', END)
        self.textbar_match.delete('1.0', END)

def New_Frame(root):
    New_frame=work_frame(root)
    global count
    count+=1
    text="Dict"+str(count)
    nb.add(New_frame.frame,text=text)

    
if __name__=="__main__":
    root=Tk()
    root.title("PD_Manager")
    
    dict={}
    
    menu=Menu(root)
    root.config(menu=menu)
    
    submenu=Menu(menu)
    menu.add_cascade(label="File",menu=submenu)
        
    submenu.add_command(label="New",command=lambda: New_Frame(root))
    submenu.add_separator()
    submenu.add_command(label="Quit",command=root.destroy)
    
    nb=ttk.Notebook(root)
    nb.pack(side=LEFT)
    
    New_Frame(root)
    root.mainloop()
