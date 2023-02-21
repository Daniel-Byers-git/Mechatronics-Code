# Topics
# Magic or Dunder methods 
# Main, Lambda,  

def double(param = 0):
    return param * param


def lambda_ex():
    # lambda pramaters: function
    
    var = lambda p1: p1*p1
    var2 = lambda x, y: x*x*y
    var3 = lambda x, y, z: x*x*y/z
    print(var(2)) 
    print(var2(2,3)) 
    print(var3(2,2,3)) 
    a = [2,3,4,5,6,7,8,9,10]
    f = lambda x: x % 2 == 0
    filtered = filter (f, a)
    print(list(filtered)) 

#W3 School Example
def myfunc(n):
    return lambda a : a * n

var = myfunc(2)
var(5)


# https://vegibit.com/python-recursion-examples/
def backwardsby2(num):
    if num <= 0:
        print('Zero!')
        return
    else:
        emojismiles = []
        for i in range(0, num):
            emojismiles += '😃'
        print(num, ' '.join(emojismiles))
        backwardsby2(num - 2)
backwardsby2(9)

def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

def main():
    print('This is the main class')
    lambda_ex()

    doubler = myfunc(2)
    print(doubler(3))
    doubler = lambda param1: param1 * 2
    print(doubler(3))
    tripler = myfunc(3)
    print(tripler(3))
    # tripler = lambda a: a*3

    # single line statements
    numbers = tuple(x for x in range(20) if x % 2 == 0)
    # list = []
    # for i in range(20):
    #     if i % 2 == 0:
    #         list.append(i)
    # tup = tuple(list)
    # print(tup)
    print(numbers)

    num = 4
    # output if cond else output2 if cond2 else output3
    # if cond: 
    #   output
    # elif cond2
    #   output2 
    # else
    #   output3 
    print('single line') if num == 5 else print('num != 5') if num == 4 else print('I dont know')

    # C++ can use ? for single line conditional
    # var = (y < 10) ? 30 : 40;
    # con ? true : false

    number = 17
    print('Fibonacci sequence:')
    for i in range(number):
        print(fibonacci(i))

if __name__ == "__main__":
    main()