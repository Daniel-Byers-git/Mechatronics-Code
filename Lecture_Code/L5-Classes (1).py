import ClassFolder.CustomClass as CustomClass
#Package = ClassFolder

def main():
    # print('This is out main function')
    class_obj = CustomClass.Custom(pass_in_2 = 2)
    # print('After Object')
    class_obj.random_function()

#Dunder methods or magic methods
if __name__ == "__main__":
    main()