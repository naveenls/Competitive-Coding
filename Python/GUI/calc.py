# -*- coding: utf-8 -*-
"""
Created on Thu May 23 13:08:48 2019

@author: HP
"""

from tkinter import *
from tkinter import ttk
import tkinter.messagebox as tkm

count=0

class photos:
    def __init__(self):
        self.photo0=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\0.png')
        self.photo1=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\1.png')
        self.photo2=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\2.png')
        self.photo3=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\3.png')
        self.photo4=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\4.png')
        self.photo5=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\5.png')
        self.photo6=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\6.png')
        self.photo7=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\7.png')
        self.photo8=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\8.png')
        self.photo9=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\9.png')
        self.photop=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\p.png')
        self.photoc=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\c.png')
        self.photoe=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\e.png')
        self.photos=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\s.png')
        self.photom=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\m.png')
        self.photod=PhotoImage(file=r'F:\CS Projects\Coding\Python\Input\Numbers\d.png')

class math_button:
    def __init__(self,master,parent,photo):
        self.button1 = Button(master, image=photo.photo1, command=lambda: parent.press(1)) 
        self.button1.grid(row=1, column=0)
        self.button2 = Button(master, image=photo.photo2, command=lambda: parent.press(2)) 
        self.button2.grid(row=1, column=1)
        self.button3 = Button(master, image=photo.photo3, command=lambda: parent.press(3)) 
        self.button3.grid(row=1, column=2)
        self.button4 = Button(master, image=photo.photo4, command=lambda: parent.press(4)) 
        self.button4.grid(row=2, column=0)
        self.button5 = Button(master, image=photo.photo5, command=lambda: parent.press(5)) 
        self.button5.grid(row=2, column=1)
        self.button6 = Button(master, image=photo.photo6, command=lambda: parent.press(6)) 
        self.button6.grid(row=2, column=2)
        self.button7 = Button(master, image=photo.photo7, command=lambda: parent.press(7)) 
        self.button7.grid(row=3, column=0)
        self.button8 = Button(master, image=photo.photo8, command=lambda: parent.press(8)) 
        self.button8.grid(row=3, column=1)
        self.button9 = Button(master, image=photo.photo9, command=lambda: parent.press(9)) 
        self.button9.grid(row=3, column=2)
        self.button0 = Button(master, image=photo.photo0, command=lambda: parent.press(0)) 
        self.button0.grid(row=4, column=0)
        self.buttonp = Button(master, image=photo.photop, command=lambda: parent.press('+')) 
        self.buttonp.grid(row=1, column=3)
        self.buttonm = Button(master, image=photo.photom, command=lambda: parent.press('*')) 
        self.buttonm.grid(row=2, column=3)
        self.buttond = Button(master, image=photo.photod, command=lambda: parent.press('/')) 
        self.buttond.grid(row=3, column=3)
        self.buttons = Button(master, image=photo.photos, command=lambda: parent.press('-')) 
        self.buttons.grid(row=4, column=3)
        self.buttone = Button(master, image=photo.photoe, command=lambda: parent.evaluate()) 
        self.buttone.grid(row=4, column=1)
        self.buttonc = Button(master, image=photo.photoc, command=lambda: parent.clear()) 
        self.buttonc.grid(row=4, column=2)
        
class work_frame:
    def __init__(self,master):
        self.frame=Frame(master)
        self.frame.config(bd=4,background="light green")
        self.frame.pack()
        self.expression=""
        self.equation = StringVar()
        expression_field = Entry(self.frame, textvariable=self.equation)
        expression_field.grid(row=0,columnspan=4)
        self.equation.set('Enter your expression') 
        self.photo=photos()
        buttons=math_button(self.frame,self,self.photo)
        
    def clear(self):
        self.expression=""
        self.equation.set("")
        
    def press(self,num):
        self.expression=self.expression+str(num)
        self.equation.set(self.expression)
        
    def evaluate(self):
        try:
            total=str(eval(self.expression))
            self.equation.set(total)
            self.expression=""
        except:
            tkm.showwarning(title="Invalid Input",message="Given syntax is incorrect")
            self.equation.set("Error")
            self.expression=""

def New_Frame(root):
    New_frame=work_frame(root)
    global count
    count+=1
    text="Frame"+str(count)
    nb.add(New_frame.frame,text=text)
    
def New_wind():
    root1=Tk()
    root1.mainloop()
    
if __name__ == "__main__":   
    root=Tk()
    root.title("Simple Calculator")
    menu=Menu(root)
    root.config(menu=menu)
    
    submenu=Menu(menu)
    menu.add_cascade(label="File",menu=submenu)
    
    submenu.add_command(label="New",command=lambda: New_Frame(root))
    submenu.add_command(label="New wind",command=lambda: New_wind())
    submenu.add_separator()
    submenu.add_command(label="Quit",command=root.destroy)

    nb=ttk.Notebook(root)
    nb.pack(side=LEFT)
    
    New_Frame(root)
    root.mainloop()