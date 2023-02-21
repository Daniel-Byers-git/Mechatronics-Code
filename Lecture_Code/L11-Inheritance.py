# # https://www.tutorialspoint.com/inheritance-in-python
# # Base Class
class Base():
    # constructor of base class
    def __init__(self, name, id):
        self.name = name
        self.id = id
    def display(self):
        print(self.name)
        print(self.id)
# # Derived Class

class Derived( Base ):
    def __init__(self, name, id, date, location):
        self.date = date
        self.location = location
        # invoking the __init__ of the parent class
        Base.__init__(self, name, id)
# # child class
class Clothing_Store( Base ):
    def __init__(self, name, id, referred, location):
        self.referred = referred
        self.location = location
        # invoking the __init__ of the parent class
        Base.__init__(self, name, id)
    def display(self):
        print(self.name)
        print(self.id)
        print(self.referred)
        print(self.location)
# # creation of an object for base/derived class
objA = Derived('FirstName LastName', 1234, 2021, "Atlanta")
objA.display()
objB = Clothing_Store('FirstName2 LastName2',4567,True,"Marietta")
objB.display()

# To inherit from multiple classes
# class Class_Name( Base1, Base2 ):
