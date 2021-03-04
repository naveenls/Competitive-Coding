class Employee:
    def __init__(self,a,b):
        self.first=a
        self.second=b
        
    def play(self,other):
        return Employee(self.first+other.first,self.second+other.second)
    __add__=play
    def __repr__(self):
        return '{}-{}'.format(self.first,self.second)
    
    @property
    def summ(self):
        return self.first+self.second
    
    @summ.setter
    def summ(self,num):
        self.second=num%10
        num=int(num/10)
        self.first=num
    
a=Employee(5,6)
b=Employee(6,7)

def world1():
    print("hi")
    
str="world1"

print(str())