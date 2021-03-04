# -*- coding: utf-8 -*-
"""
Created on Wed May 22 10:24:35 2019

@author: HP
"""

from tkinter import *
import tkinter.messagebox as tkm

def func_none():
    print("Nothing")

def func_l(event):
    print("Hi all")
    
root=Tk()

menu=Menu(root)
root.config(menu=menu)

tkm.showinfo(title="Message Box",message="Hi all")
answer=tkm.askquestion(title="Message",message="are u alive")

if answer=="yes":
    print("congrats")
else:
    print("sorry")

submenu=Menu(menu)
menu.add_cascade(label="File",menu=submenu)
submenu.add_command(label="New",command=func_none)
submenu.add_command(label="Open",command=func_none)
submenu.add_separator()
submenu.add_command(label="Quit",command=func_none)

submenu1=Menu(menu)
menu.add_cascade(label="Edit",menu=submenu1)
submenu1.add_command(label="Copy",command=func_none)
submenu1.add_command(label="Paste",command=func_none)
submenu1.add_separator()
submenu1.add_command(label="Quit",command=func_none)

toolbar=Frame(root,bg="blue")
button1=Button(toolbar,text="Insert",command=func_none)
button1.pack(side=LEFT,padx=2,pady=2)
button1=Button(toolbar,text="Delete",command=func_none)
button1.pack(side=LEFT,padx=2,pady=2)
toolbar.pack(side=TOP,fill=X)

topframe=Frame(root)
topframe.pack()
bottomframe=Frame(root)
bottomframe.pack()

lable1=Label(topframe,text="Name")
lable2=Label(topframe,text="Password")
entry1=Entry(topframe)
entry2=Entry(topframe)

lable1.grid(row=0)
lable2.grid(row=1)
entry1.grid(row=0,column=1)
entry2.grid(row=1,column=1)

c=Checkbutton(topframe,text="keep me logged in")
c.grid(columnspan=2)

button1=Button(bottomframe,text="Submit",fg="red",bg="blue")
button1.bind("<Button-1>",func_l)
button1.pack()

status=Label(root,text="Nothing",bd=5,relief=SUNKEN,anchor=W)
status.pack(side=BOTTOM,fill=X)

canvas=Canvas(root,width=200,height=100)
canvas.create_rectangle(0,0,200,100,fill="red")
canvas.pack(side=BOTTOM)

photo=PhotoImage(file='Submit_Button.png')
	# create a Submit Button and place into the root window 
submit = Button(root, image=photo,bg="white") 
submit.grid(row=8, column=1)
root.mainloop()
