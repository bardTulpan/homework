from abc import ABC, abstractmethod

class ChessPiece(ABC):
    def __init__(self, horizontal, vertical):
        self.horizontal = horizontal
        self.vertical = vertical

    @abstractmethod
    def can_move(self, horizontal, vertical):
        pass

class King(ChessPiece):
    def can_move(self, h, v):
        curr_h = ord(self.horizontal)
        target_h = ord(h)
        
        diff_h = abs(curr_h - target_h)
        diff_v = abs(self.vertical - v)
        
        return diff_h <= 1 and diff_v <= 1

class Knight(ChessPiece):
    def can_move(self, h, v):
        curr_h = ord(self.horizontal)
        target_h = ord(h)
        
        diff_h = abs(curr_h - target_h)
        diff_v = abs(self.vertical - v)
        
        return (diff_h == 2 and diff_v == 1) or (diff_h == 1 and diff_v == 2)

king = King('e', 4)
knight = Knight('b', 1)
print(f"Король e4 -> e5: {king.can_move('e', 5)}")
print(f"Конь b1 -> c3: {knight.can_move('c', 3)}")
