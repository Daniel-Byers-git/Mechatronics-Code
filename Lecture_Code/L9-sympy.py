from sympy import * 
x=Symbol ('x') 
y=Symbol ('y') 
expr = integrate(y**x, y) 
pprint(expr)

pprint(sqrt(7))
print(sqrt(7))

pprint(Rational(3/4))
print(Rational(.2))

print(Rational(0.2).limit_denominator(100))

a=Rational(3,5) 
print (a) 
print ("numerator:{}, denominator:{}".format(a.p, a.q))
print (f"numerator:{a.p}, denominator:{a.q}")

i=sqrt(-1) 
pprint(i)
print(i*i)

print(S.ImaginaryUnit)
#---------------------------------
expr=x**2+y**2 
print(expr)
pprint(expr)

from sympy.abc import x,a 
expr=sin(x)*sin(x)+cos(x)*cos(x) 
print(expr)
print(expr.subs(x,a))
pprint(expr.subs(x,a))

expr="x**2+3*x+2" 
expr1=sympify(expr) 
print(expr1) 
print(expr1.subs(x,2))

print(sympify("10/5+4/2", evaluate=True))
print(sympify("10/5+4/2", evaluate=False))

from sympy.abc import r 
expr=pi*r**2 
print(expr.evalf(subs={r:5}))

a,b=symbols('a b') 
print(expand((a+b)**2))
pprint(factor(x**2+2*x+1))

expr=factorial(x)/factorial(x - 3) 
print(expr)
pprint(expr)

print(combsimp(expr))
#deivative
print(diff(x**4,x,3))

expr=exp(-x**2 - y**2)
pprint(integrate(expr,(x,0,oo),(y,0,oo)))

print(solveset(Eq(x**2-9,0), x))
print(linsolve([ Eq( x - y , 4 ), Eq( x + y , 1 ) ], (x, y)))

