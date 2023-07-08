import heapq

def dijkstra(graph, start, end):
    distances = {vertex: float('inf') for vertex in graph}
    distances[start] = 0

    queue = [(0, start)]

    while queue:
        current_distance, current_vertex = heapq.heappop(queue)

        if current_vertex == end:
            return distances[current_vertex]

        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex].items():
            new_distance = current_distance + weight

            if new_distance < distances[neighbor]:
                distances[neighbor] = new_distance
                heapq.heappush(queue, (new_distance, neighbor))

    return -1


n, m = map(int, input().split())

graph = {i: {} for i in range(1, n + 1)}

for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u][v] = w

start, end = map(int, input().split())

shortest_distance = dijkstra(graph, start, end)

print(shortest_distance)
 
