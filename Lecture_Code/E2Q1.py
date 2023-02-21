class lateral:
    def __init__(self, left = 7, right = 8):
        self.left = left
        self.right = right
    def __str__(self):
        return f"left: {self.left} right: {self.right}"
    def __sub__(self, rhs):
        self.right = self.right - rhs
    def __rsub__(self, lhs):
        self.left = self.left + lhs

lat1 = lateral()
lat2 = lateral(left = 5, right = 10)
print(lat2)
1 - lat1
lat1 - 2
print(lat1)

class course:
    def __init__(self, title, crn):
        self.title = title
        self.crn = crn
    def __str__(self):
        return f"course: {self.title} CRN: {self.crn}"
   
class lab(course):
    def __init__(self, title, crn, fee):
        course.__init__(self, title, crn)
        self.fee = fee
    def __str__(self):
        return f"course: {self.title} CRN: {self.crn} Fee: {self.fee}"

no_lab_course = course('Intermediate Prog', 2260)    
lab_course = lab('Intermediate Prog', 2260, 100) 
print(no_lab_course)
print(lab_course)

for index in range(0,10):
    print(index)

list = [1,3,4,5]
for index,val in enumerate(list):
    print(index,val)

import numpy as np
import matplotlib.pyplot as plt
x = np.linspace(0, 2*np.pi, 100)
y = np.sin(2*x)-np.cos(3*x)
plt.plot(x,y, label="exam eq")
plt.xlabel('X-Axis')
plt.ylabel('Y-Axis')
plt.title('Plotting Sin2x-Cos3x')
plt.legend()
# plt.show()

from sympy import *
x=Symbol ('x') 
y=Symbol ('y') 
equation = diff(x**4+x**2-x,x,1)
pprint(equation)
print(equation.evalf(subs={x:5}))

eq1 = Eq(3*x + 2*y + 5, 0)
eq2 = Eq(2*x + y, 7)
print(linsolve([eq1,eq2], (x, y)))