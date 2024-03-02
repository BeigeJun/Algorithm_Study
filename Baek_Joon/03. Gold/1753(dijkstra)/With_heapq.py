import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for after, weight in graph[now]:
            cost = dist + weight
            if cost < distance[after]:
                distance[after] = cost
                heapq.heappush(q, (cost, after))

V, E = map(int, input().split())
start_node = int(input())
graph = [[] for _ in range(V)]

distance = [INF] * V
for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u - 1].append((v - 1, w))

dijkstra(start_node - 1)

for dist in distance:
    print("INF" if dist == INF else dist)
