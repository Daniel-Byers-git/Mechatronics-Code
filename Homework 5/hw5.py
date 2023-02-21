import numpy as np

# ! Question one

matrix = np.empty((4,4))

row, col = matrix.shape

for r in range (0, row):
    for c in range (0, col):
        matrix[r][c] = np.random.randint(3,13)

print(matrix)

print(matrix.sum())

for r in range (1,3):
    for c in range (1,3):
        matrix[r][c] = 0;

print(matrix)

# ! Question two

pi = total = inside = 0

while( abs((pi - 3.1415926535)) > 1e-4):
    total += 1
    x = np.random.rand()
    y = np.random.rand()
    if (y < np.sqrt(1 - x**2)): 
        inside += 1
    pi = ( inside / total ) * 4 

print(pi)

# ! Question three

i = integers = 0

while (i**2.5 < 1000000):
    i += 1
    integers += 1

print('there are ', integers, ' integers for which i^2.5 < 1,000,000')
