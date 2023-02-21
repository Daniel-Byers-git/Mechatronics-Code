class sample:
    def __init__(self, val = 0):
        print('Class Constructor')
        self.var = val
    def method(self):
        print(self.var)
    def __del__(self):
        pass
    def __add__(self, RHS):
        print('Operator Overload')
        print(type(RHS))

        if(type(RHS) == type(self)):
            print('Class Obj Type')
        elif(type(RHS) == type(int())): #type(str()) #type(float()) #type(list())
            print('integer type')
        # if(str(type(RHS)) == "<class '__main__.sample'>")
    def __radd__(self, LHS): #__mul__, __div__
        print('LHS' + str(LHS))
        print(f'LHS {LHS}')


# class_obj = sample(7)
# print(class_obj.var)
s1 = sample()
s2 = sample(7)
s1 + s2
"THis is passed in" + s1
# import sample

# def main():
#     pass

# if __name__ == '__main__':
#     main()