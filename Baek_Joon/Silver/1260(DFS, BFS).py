import sys
def dfs(idx):
    global Visited
    Visited[idx] = True
    print(idx, end = ' ')
    for next in range(1, N + 1):
        if not Visited[next] and Graph[idx][next]:
            dfs(next)

def bfs():
    global q, Visited
    while q:
        cur = q.pop(0)
        print(cur, end = ' ')
        for next in range(1, N + 1):
            if not Visited[next] and Graph[cur][next]:
                Visited[next] = True
                q.append(next)

input = sys.stdin.readline
N, M, V = map(int, input().split())

Graph = [[False] * (N + 1) for _ in range(N + 1)] #_는 변수의 사용이 없을 때 사용된다.
Visited = [False] * (N + 1)

for _ in range(M):
    a, b = map(int, input().split())
    Graph[a][b] = True
    Graph[b][a] = True

dfs(V)
print()

Visited = [False] * (N + 1)
q = [V]
Visited[V] = True
bfs()
