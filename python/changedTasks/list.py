n, m = map(int, input().split())
field = [list(input().strip()) for _ in range(n)]

count = 0

for i in range(n):
    for j in range(m):
        if field[i][j] == '.':
            can_place = True

            if i > 0 and field[i-1][j] == '*':
                can_place = False
            if i < n-1 and field[i+1][j] == '*':
                can_place = False
            if j > 0 and field[i][j-1] == '*':
                can_place = False
            if j < m-1 and field[i][j+1] == '*':
                can_place = False
            
            if can_place:
                count += 1

print(count)