import math

class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def length(self):
        return math.sqrt(self.x**2 + self.y**2)
    
    def angle(self):
        return math.atan2(self.y, self.x)
    
    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)
    
    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)
    
    def dot_product(self, other):
        return self.x * other.x + self.y * other.y