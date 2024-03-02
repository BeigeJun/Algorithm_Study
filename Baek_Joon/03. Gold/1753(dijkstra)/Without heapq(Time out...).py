import sys
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start):
    distance[start] = 0

    for i in range(V):
        min = INF
        now = -1
        for i in range(V):
            if (distance[i] < min and visited[i] != True):
                min = distance[i]
                now = i

        if now == -1:
            break

        visited[now] = True

        for after, weight in graph[now]:
            cost = min + weight
            if cost < distance[after]:
                distance[after] = cost


V, E = map(int,input().split()) #정점, 간선의 개수 받기
start_node = int(input()) #시작점 받기
graph = [[] for _ in range(V)] #2차원 배열 생성


distance = [INF] * (V) #거리는 무제한으로 초기화
visited = [False] * (V)

for _ in range(E):
    u, v, w = map(int,input().split()) #u->v로 가는 가중치 w 입력받기
    graph[u - 1].append((v - 1, w))

dijkstra(start_node - 1)

for i in range(0,V):
    if distance[i] == INF:
        print("INF")
    else:
        print(distance[i])
