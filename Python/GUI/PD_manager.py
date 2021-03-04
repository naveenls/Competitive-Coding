# -*- coding: utf-8 -*-
"""
Created on Sat Aug 10 18:20:15 2019

@author: HP
"""

from tkinter import *
from tkinter import ttk
import tkinter.messagebox as tkm

count=0

class Node:
    def __init__(self):
        self.name=None
        self.course=None
        self.sem=None
        self.contact=None
        self.email=None
        self.hostel=None
        self.count=0
        self.dict={0: self.name,1: self.course,2: self.sem,3: self.contact,4: self.email,5: self.hostel}
        
    def insert(self,word):
        self.dict[self.count]=word
        self.count=self.count+1
        
class work_frame:
    def __init__(self,master):
        self.frame=Frame(master)
        self.topframe=Frame(self.frame)
        self.middleframe=Frame(self.frame,pady=6)
        self.bottomframe=Frame(self.frame)
        
        self.text=Label(self.topframe,text="Search")
        self.word=Entry(self.topframe)
        
        self.text.grid(row=0)
        self.word.grid(row=0,column=1)
        
        self.textbar=Text(self.middleframe,height=5,spacing2=1,width=50)
        self.textbar.grid(row=0,column=0)
        
        self.textbar_match=Text(self.middleframe,height=5,spacing2=1,width=20)
        self.textbar_match.grid(row=0,column=1)
        
        self.search=Button(self.bottomframe,text="Search",command=self.search,padx=50)
        self.clear=Button(self.bottomframe,text="Clear",command=self.clear,padx=50)
        
        self.search.grid(row=0,column=0)
        self.clear.grid(row=0,column=1)
        
        self.topframe.pack(side=TOP)
        self.middleframe.pack()
        self.bottomframe.pack(side=BOTTOM)
        
    def search(self):
        self.textbar.delete('1.0', END)
        self.textbar_match.delete('1.0', END)
        w=self.word.get()
        try:
            details=dict[w]
            dic={0: "Name: ",1: "Course: ",2: "Semester: ",3: "Contact No: ",4: "Email ID: ",5: "Hostel: "}
            for i in range(6):
                field=details.dict[i]
                self.textbar.insert(INSERT,dic[i])
                self.textbar.insert(INSERT,field + '\n')
        except:
            self.textbar.insert(INSERT,"No details found")
        self.matching(w)
            
    def matching(self,word):
        self.textbar_match.insert(INSERT,"Matching Names:" + '\n')
        for w in dict:
            l=len(w)
            lw=len(word)
            if(l>len(word)):
                w1=w[0:lw]
                w2=w[l-lw:l]
                if hash(word)==hash(w1) or hash(word)==hash(w2):
                    self.textbar_match.insert(INSERT,w + '\n')
        
    def clear(self):
        self.word.delete(0,'end')
        self.textbar.delete('1.0', END)
        self.textbar_match.delete('1.0', END)
        
        
class New_window:
    def __init__(self):
        self.top_level=Tk()
        self.top_level.title("Add Detail")
        
        self.frame=Frame(self.top_level)
        self.bottomframe=Frame(self.top_level)
    
        self.name=Label(self.frame,text="Name:")
        self.course=Label(self.frame,text="Course:")
        self.sem=Label(self.frame,text="Semester:")
        self.contact=Label(self.frame,text="Contact No.:")
        self.email=Label(self.frame,text="Email ID:")
        self.hostel=Label(self.frame,text="Hostel Name:")
        
        self.entries=[]
        
        self.namef=Entry(self.frame)
        self.entries.append(self.namef)
        self.coursef=Entry(self.frame)
        self.entries.append(self.coursef)
        self.semf=Entry(self.frame)
        self.entries.append(self.semf)
        self.contactf=Entry(self.frame)
        self.entries.append(self.contactf)
        self.emailf=Entry(self.frame)
        self.entries.append(self.emailf)
        self.hostelf=Entry(self.frame)
        self.entries.append(self.hostelf)
        
        self.name.grid(row=0, column=0) 
        self.course.grid(row=1, column=0) 
        self.sem.grid(row=2, column=0) 
        self.contact.grid(row=3, column=0) 
        self.email.grid(row=4, column=0) 
        self.hostel.grid(row=5, column=0)  
        
        
        self.namef.bind("<Return>",lambda x: self.focus(1)) 
        self.coursef.bind("<Return>",lambda x: self.focus(2)) 
        self.semf.bind("<Return>",lambda x: self.focus(3)) 
        self.contactf.bind("<Return>",lambda x: self.focus(4)) 
        self.emailf.bind("<Return>",lambda x: self.focus(5))
        self.hostelf.bind("<Return>",lambda x: self.focus(0)) 
        
        self.namef.grid(row=0, column=1) 
        self.coursef.grid(row=1, column=1) 
        self.semf.grid(row=2, column=1) 
        self.contactf.grid(row=3, column=1) 
        self.emailf.grid(row=4, column=1) 
        self.hostelf.grid(row=5, column=1) 
        
        self.add=Button(self.bottomframe,text="Insert",command=self.Insert,padx=30)
        self.Quit=Button(self.bottomframe,text="Quit",command=self.top_level.destroy,padx=30)
        
        self.add.grid(row=0,column=0)
        self.Quit.grid(row=0,column=1)
        
        self.frame.pack()
        self.bottomframe.pack()
        self.top_level.mainloop()
        
    def Insert(self):
        node=Node()
        for entry in self.entries:
            new_word=entry.get()
            node.insert(new_word)

        new_name=self.namef.get()
        dict[new_name]=node
        
        for entry in self.entries:
            entry.delete(0,'end')
            
        self.namef.focus_set()
        
    def focus(self,no):  
        entry=self.entries[no]
        entry.focus_set() 

    
def New_Frame(root):
    New_frame=work_frame(root)
    global count
    count+=1
    text="Dict"+str(count)
    nb.add(New_frame.frame,text=text)

def New_wind():
    new=New_window()
    del new
    
if __name__=="__main__":
    root=Tk()
    root.title("PD_Manager")
    
    dict={}
    
    menu=Menu(root)
    root.config(menu=menu)
    
    submenu=Menu(menu)
    menu.add_cascade(label="File",menu=submenu)
    
    submenu1=Menu(menu)
    menu.add_cascade(label="Edit",menu=submenu1)
    
    submenu.add_command(label="New",command=lambda: New_Frame(root))
    submenu.add_separator()
    submenu.add_command(label="Quit",command=root.destroy)
    
    submenu1.add_command(label="Add Word",command=New_wind)
    
    nb=ttk.Notebook(root)
    nb.pack(side=LEFT)
    
    New_Frame(root)
    root.mainloop()
    
    