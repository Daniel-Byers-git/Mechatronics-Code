import argparse

#variable arguments *
def method_a(*args):
    print(args[0])
    print(args[1])
    print(args[2])
    for arg in args:
        print (arg)
#Keyword argument **

def method_kw(**kwargs):
    print(kwargs['x'])
    print(kwargs['y'])
    print(kwargs['z'])
    for key in kwargs:
        print(key, kwargs[key])

#global variable and normat method declaration 
global_var = 10
def method(x = None, y = None, z = None):
    global global_var
    global_var = 20
    print(global_var)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-s", "--sample", help="argument helper", type=str, default=None)
    parser.add_argument("-r", "--retry", help="retry helper", type=int, default=0)
    args = parser.parse_args()
    print(args.sample)
    print(args.retry)

    # method_a(1,2,3,4,5,6,7)
    # method_kw(x=1,y=2,z=3, sample_values = 7)
    # method()
    # print(global_var)

    # print(range(1,10,2))
    # a = range(1,10,2)
    # print (a)
    # for item in a:
    #     print (item)
    # for i in range(0,10,2):
    #     print(i)

    # for index, value in enumerate(list(['a','b','c'])):
    #     print(index,value)
    # # splicing uses : syntax = start:end:step
    # list_var = [1,4,5,6,8]
    # print(list_var[-3:])
    # print(list_var[2:4])
    # print(list_var[::2])

    # var_a = 10
    # var_b = 'this'
    # if(var_a == 10):
    #     print ('that is correct')
    # if(var_b is 'this'):
    #     print('correct')
    # if('thx' in var_b):
    #     print('it is include')
    # if(var_b is not 'this'): 
    #     print('this is true')
    # string_var = 'python string var'
    # print(string_var[0:6])
    # obj = string_var.split(' ')
    # csv = '1,2,4,5,6,7,8,20'
    # obj2 = csv.split(',')
    # for index, val in enumerate(obj2):
    #     print(index, int(val))
    #     obj2[index] = int(val)

    # print(obj2)

if __name__ == "__main__":
    main()


