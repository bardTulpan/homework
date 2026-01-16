arr = list(map(int, input().split()))
ans = set()

for x in arr:
    if arr.count(x) > 1:
        ans.add(x)

print(*ans)

