n = int(input())
intervals = []

for _ in range(n):
    a, b = map(int, input().split())
    intervals.append((a, b))

time = int(input())
count = 0

for a, b in intervals:
    if a <= time <= b:
        count += 1

print(count)