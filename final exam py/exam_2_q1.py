class lateral:
    def __init__(self, left = 7, right = 7):
        self.left = left
        self.right = right
    def __rmul__(self, LHS):
        self.left += LHS
    def __truediv__(self, RHS):
        self.right *= RHS
    def __str__(self):
        return (f"left:{self.left} right:{self.right}")

lat1 = lateral()
lat2 = lateral(left = 5, right = 10)
print(lat2)
1 * lat1
lat1 / 2
print(lat1)