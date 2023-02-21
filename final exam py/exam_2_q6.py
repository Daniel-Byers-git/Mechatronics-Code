from sympy import *
from numpy import pi
x = Symbol('x')
y = Symbol('y')

eq1 = Eq(3*x + 2*y + 5, 0)
eq2 = Eq(2*x + y, 7)
eq3 = Eq(5*x + 2*y, 0)

print(linsolve([eq1,eq2,eq3], (x,y)))

f_x = x**3 + x**2
print(integrate(f_x,(x,0,pi)))