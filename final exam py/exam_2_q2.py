import numpy as np

random_list = np.zeros(10)

list_file = open("list_file.txt", 'w')
for i in range(0,10):
    random_list[i] = np.random.randint(0,1000)
    list_file.write(f'{random_list[i]} \n')
list_file.close()

rand_list_arr = np.loadtxt("list_file.txt")
print(sum(rand_list_arr))
print(rand_list_arr[-2:])