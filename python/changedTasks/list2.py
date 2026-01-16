n = int(input())
cells = []

for _ in range(n):
    x, y = map(int, input().split())
    cells.append((x, y))

cell_set = set(cells)
directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

perimeter = 0

for x, y in cells:
    sides = 4 
    
    for dx, dy in directions:
        neighbor = (x + dx, y + dy)
        if neighbor in cell_set:
            sides -= 1
    
    perimeter += sides

print(perimeter)