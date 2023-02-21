# pip install matplotlib numpy keras opencv-python

# print('This is a test')
# # Comments
# def method_name():
#     print('This belongs to the method_name')

# def method_name(param = 0, param2 = None, param3 = None):
#     print('This belongs to the method_name')
#     print(f"Param2 {param2}")
#     print(f"Param {param}")

# method_name(param2 = 1)
# method_name(param3 = 2, param2 = 1)
# method_name(1,2)

# print('This is a test2')

# if (codition):
#     pass
# elif (condition2):
#     pass
# else:
#     pass

# for i in range(2,6,2):
#     pass

# def main():
#     print("this is the main method")

#DUNDER METHODS / MAGIC METHOD
# if __name__ == "__main__":
#     main()

# inputVar = input() # input = cin from c++
# print(inputVar) # print = cout in C++
# print('inputvar:', inputVar)
# print(type(inputVar))
# print(str(inputVar))
# print(int(inputVar))
# # variable types
# type() - provides type of object
# # Text Type:	str
# # Numeric Types:	int, float, complex
# Complex - a+bj or complex(a,b)
# # Sequence Types:	list, tuple, range
# # Mapping Type:	dict    || key:value
# # Set Types:	set, frozenset
# # Boolean Type:	bool
# # Binary Types:	bytes, bytearray, memoryview - Associated with bitwise operators
# print(0b00010001)
# print(bin(0b00010001))
# print(bin(17))
# print(hex(0b00011011))
# print(0xAF)


# # # typing type() will give you the type
# variable = 2.1
# print(type(variable))

# # #lists are like array's
# # #List Constructor list()
# # pyList = [] #also list() works as well
# pyList = list() #also list() works as well
# print(type(pyList))
# pyList.append(1)
# pyList.append(4)
# print(pyList)
# pyList.append('abc')
# pyList.append([2,3,4])
# print(pyList[2])
# #numpy
# pyList.insert(0,'bcd')
# print(pyList)

# #Tuples
# #Tuple Constructor tuple()
pyTup_a = (1,4,1,"many",6)
# print(pyTup_a)
# vara, varb, varc, vard, vare = pyTup_a # unpacking a tuple
# print(vara)
# print(varb)
# print(varc)

pyTup_b = (1,4)
#Tuple Concatenation
pyTup_a = pyTup_a + (5,6)
# pyListTup = list(pyTup_a)
# pyTup_a[9] = 5
# pyTup_a = tuple(pyTup_a)
print(pyTup_a)
# print(pyTup_a[0])
# print(pyTup_a[1])

# Len = gives the number of element in a string, list, tuple, etc...
# print(len(pyTup_a))

# print(pyTup_a.count(1))
# print(pyTup_a.index(4))

# variable_range = range(1,6,2)
# print(variable_range)
# for item in variable_range:
#     print(item)
#enumarate for getting the index as well

# for item in pyTup_a:
    # print(item)
# for index in range(len(pyTup_a)):
#     # print(index)
#     # print(pyTup_a[index])
#     print(index, pyTup_a[index])
for index, item in enumerate(pyTup_a):
    # print(str(index) + " : " + str(item))
    #string formatting
    print(f'Index :{{ {index} }} Item : {item}')
    print('Index :{{ {0} }} Item : {1}'.format(index,item))
    # (" %s %u %d", variable_string,variable_int, variable_double)



# #Set Constructor set()
# # pySet = set()
# # pySet.add('apple')
# # pySet.add('banana')
# # print(pySet)
# # # Cannot access sets by index or key must iterate through it
# # # pySet[index] pySet[key] does not work
# # for index, item in enumerate(pySet):
# #     print (index)
# #     print (item)

# # print('something' in pySet)
# # print(len(pySet))

# #Dictionary Constructor dict()
# # pyDict = dict()
# # pyDict['Key1'] = 'Value 1'
# # print(pyDict)
# # # or
# # pyDict.update({'Key2':'Value 2'})
# # print(pyDict)
# # # #To remove you can do two things
# # pyDict.pop('Key1')
# # # #Pop without a key will remove the last item in the dictionary
# # del pyDict['Key2']
# # print(pyDict)

# # for key, value in pyDict.items():
# #     print (key, value)

# # for key in pyDict:
# #     print(key)

# listofdict = [pyDict, 2]
# print(listofdict)

# tupleofdict = (pyDict, 2)
# print(tupleofdict)

# courses = {"students" : pyDict, "key2" : "value 2"}
# print(courses)
# # course['students']['Key1']

# #if statments and pass
# pyDict = {'Key1' : (1,2),
#           "Key2" : 2,
#           "key3" : 3}
        
# int_var = 5
# if ('Key12323' in pyDict):
#     print(f'This is a string {int_var} is the value in the curly brackets')
#     print('This is a string {0} is {1} the value in the curly brackets'.format(int_var, int_var))
# elif (int_var == 5):
#     print('Second Condition')
# else:
#     pass

# range keyword - very important in python
# range (start, stop, step_size)
# range (stop) from zero
# range (start, stop) from start to stop increments of 1

# for i in range(6):
    # print( i )
# for i in range(2,6):
#     print( i )
# for i in range(0,6,2):
#     print( i )

# # enumerate(objects) - another useful keyword
# # will provide the index and value of objects
# a_list = ['a_list', 1,4,6,7,8]
# for index, value in enumerate(a_list):
#     print( index, value )
#     print( f'{index} : {value}' )

# #can also use the in/not in keyword 
# for item in a_list:
#     print(item)

# #While Loops
# #The Break and Continue persist in python
# #break = will break current running loop either for loop or while loop
# #continue = will skip an iteration in a loop
# condition = True
# while (condition):
#     condition = False
# else:
#     print('python allows for else condition in while')

# var_i = 0
# while (var_i < 3):
#     # var_i++ no longer works in python
#     var_i += 1
#     print(var_i)

#Iterator in python // like a pointer iterator
# pyIter = iter(a_list)
# print(next(pyIter))
# print(next(pyIter))
# print(next(pyIter))
# print(pyIter)

#Colon Notation
# [start:stop:step]
# print(a_list[3:5])
# print(a_list[0:6:2])

#Python allows for negative indexes
# print(a_list[-1])
# print(a_list[-2])
# #colon without a value = start or end depending on location
# #3: = 3 to end
# #:3 = 0 to 3 not including 3rd index
# print(a_list[-4:-2])
# print(a_list[:3])

# # Reference Location www.w3schools.com

# #Tuple Methods
# # count()	Returns the number of times a specified value occurs in a tuple
# # index()	Searches the tuple for a specified value and returns the position of where it was found

# # List Methods
# # append()	Adds an element at the end of the list
# # clear()	Removes all the elements from the list
# # copy()	Returns a copy of the list
# # count()	Returns the number of elements with the specified value
# # extend()	Add the elements of a list (or any iterable), to the end of the current list
# # index()	Returns the index of the first element with the specified value
# # insert()	Adds an element at the specified position
# # pop()	Removes the element at the specified position
# # remove()	Removes the item with the specified value
# # reverse()	Reverses the order of the list
# # sort()	Sorts the list

# #Set Methods
# # add()	Adds an element to the set
# # clear()	Removes all the elements from the set
# # copy()	Returns a copy of the set
# # difference()	Returns a set containing the difference between two or more sets
# # difference_update()	Removes the items in this set that are also included in another, specified set
# # discard()	Remove the specified item
# # intersection()	Returns a set, that is the intersection of two other sets
# # intersection_update()	Removes the items in this set that are not present in other, specified set(s)
# # isdisjoint()	Returns whether two sets have a intersection or not
# # issubset()	Returns whether another set contains this set or not
# # issuperset()	Returns whether this set contains another set or not
# # pop()	Removes an element from the set
# # remove()	Removes the specified element
# # symmetric_difference()	Returns a set with the symmetric differences of two sets
# # symmetric_difference_update()	inserts the symmetric differences from this set and another
# # union()	Return a set containing the union of sets
# # update()	Update the set with the union of this set and others

# #Dictonary
# # clear()	Removes all the elements from the dictionary
# # copy()	Returns a copy of the dictionary
# # fromkeys()	Returns a dictionary with the specified keys and value
# # get()	Returns the value of the specified key
# # items()	Returns a list containing a tuple for each key value pair
# # keys()	Returns a list containing the dictionary's keys
# # pop()	Removes the element with the specified key
# # popitem()	Removes the last inserted key-value pair
# # setdefault()	Returns the value of the specified key. If the key does not exist: insert the key, with the specified value
# # update()	Updates the dictionary with the specified key-value pairs
# # values()	Returns a list of all the values in the dictionary

# #Math Operators
# # +	Addition	x + y	
# # -	Subtraction	x - y	
# # *	Multiplication	x * y	
# # /	Division	x / y	
# # %	Modulus	x % y	
# # **	Exponentiation	x ** y	
# #  //	Floor division	x // y

# # Assignment Operators
# # =	x = 5	x = 5	
# # +=	x += 3	x = x + 3	
# # -=	x -= 3	x = x - 3	
# # *=	x *= 3	x = x * 3	
# # /=	x /= 3	x = x / 3	
# # %=	x %= 3	x = x % 3	
# # //=	x //= 3	x = x // 3	
# # **=	x **= 3	x = x ** 3	
# # &=	x &= 3	x = x & 3	
# # |=	x |= 3	x = x | 3	
# # ^=	x ^= 3	x = x ^ 3	
# # >>=	x >>= 3	x = x >> 3	
# # <<=	x <<= 3	x = x << 3

# # Math Comperators
# # ==	Equal	x == y	
# # !=	Not equal	x != y	
# # >	Greater than	x > y	
# # <	Less than	x < y	
# # >=	Greater than or equal to	x >= y	
# # <=	Less than or equal to	x <= y

# # Logical Comperators
# # and 	Returns True if both statements are true	x < 5 and  x < 10	
# # or	Returns True if one of the statements is true	x < 5 or x < 4	
# # not	Reverse the result, returns False if the result is true	not(x < 5 and x < 10)

# # Identiry Operators
# # is 	Returns True if both variables are the same object	x is y	
# # is not	Returns True if both variables are not the same object	x is not y

# # Membership Operators
# # in 	Returns True if a sequence with the specified value is present in the object	x in y	
# # not in	Returns True if a sequence with the specified value is not present in the object	x not in y

# # Bitwise Operators
# # & 	AND	Sets each bit to 1 if both bits are 1
# # |	OR	Sets each bit to 1 if one of two bits is 1
# #  ^	XOR	Sets each bit to 1 if only one of two bits is 1
# # ~ 	NOT	Inverts all the bits
# # <<	Zero fill left shift	Shift left by pushing zeros in from the right and let the leftmost bits fall off
# # >>	Signed right shift	Shift right by pushing copies of the leftmost bit in from the left, and let the rightmost bits fall off