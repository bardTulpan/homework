import heapq

def get_h(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

def run_dijkstra(matrix, start, end):
    h, w = len(matrix), len(matrix[0])
    costs = [[float('inf')] * w for _ in range(h)]
    costs[start[0]][start[1]] = 0
    
    queue = [(0, start[0], start[1])]
    
    while queue:
        curr_cost, r, c = heapq.heappop(queue)
        
        if (r, c) == end:
            return curr_cost
        
        if curr_cost > costs[r][c]:
            continue
            
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nr, nc = r + dr, c + dc
            
            if 0 <= nr < h and 0 <= nc < w:
                if abs(matrix[r][c] - matrix[nr][nc]) <= 100:
                    new_cost = curr_cost + 1
                    if new_cost < costs[nr][nc]:
                        costs[nr][nc] = new_cost
                        heapq.heappush(queue, (new_cost, nr, nc))
    return float('inf')

def run_astar(matrix, start, end):
    h, w = len(matrix), len(matrix[0])
    g_score = [[float('inf')] * w for _ in range(h)]
    g_score[start[0]][start[1]] = 0
    
    f_start = get_h(start, end)
    queue = [(f_start, start[0], start[1])]
    
    while queue:
        priority, r, c = heapq.heappop(queue)
        
        if (r, c) == end:
            return g_score[r][c]
            
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nr, nc = r + dr, c + dc
            
            if 0 <= nr < h and 0 <= nc < w:
                if abs(matrix[r][c] - matrix[nr][nc]) <= 100:
                    tentative_g = g_score[r][c] + 1
                    if tentative_g < g_score[nr][nc]:
                        g_score[nr][nc] = tentative_g
                        f_score = tentative_g + get_h((nr, nc), end)
                        heapq.heappush(queue, (f_score, nr, nc))
    return float('inf')

def main():
    line1 = input().split()
    if not line1: return
    n, m = map(int, line1)
    
    grid = []
    for _ in range(n):
        grid.append(list(map(int, input().split())))
        
    s_r, s_c = map(int, input().split())
    c_r, c_c = map(int, input().split())
    f_r, f_c = map(int, input().split())
    
    start_point = (s_r, s_c)
    cargo_point = (c_r, c_c)
    finish_point = (f_r, f_c)

    d_part1 = run_dijkstra(grid, start_point, cargo_point)
    d_part2 = run_dijkstra(grid, cargo_point, finish_point)
    print(f"Dijkstra: {d_part1 + d_part2}")

    a_part1 = run_astar(grid, start_point, cargo_point)
    a_part2 = run_astar(grid, cargo_point, finish_point)
    print(f"A-Star: {a_part1 + a_part2}")

if __name__ == "__main__":
    main()
