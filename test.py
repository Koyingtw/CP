def solve():
    n, m = map(int, input().split())
    roads = [[] for _ in range(n + 1)]
    for _ in range(m):
        a, b = map(int, input().split())
        roads[b].append(a)

    dp = [[0.0] * (n + 1) for _ in range(n + 1)]
    for v in range(1, n + 1):
        dp[n][v] = 1.0

    for v in range(1, n):
        for u in roads[v]:
            p = 1.0 / len(roads[v])
            dp[u][v] = max(dp[u][v], p * dp[v][v] + (1 - p) * dp[u][v])

    print(dp[1][1])

t = int(input())
for _ in range(t):
    solve()