import heapq

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]

    def add_edge(self, u, v, w):
        self.graph[u].append((v, w))
        self.graph[v].append((u, w))  # Assuming the graph is undirected

    def dijkstra(self, src):
        dist = [float('inf')] * self.V
        dist[src] = 0

        min_heap = [(0, src)]  # Priority queue to store (distance, vertex) pairs

        while min_heap:
            curr_dist, u = heapq.heappop(min_heap)

            if curr_dist > dist[u]:
                continue

            for neighbor, weight in self.graph[u]:
                if dist[u] + weight < dist[neighbor]:
                    dist[neighbor] = dist[u] + weight
                    heapq.heappush(min_heap, (dist[neighbor], neighbor))

        return dist

def print_solution(distances):
    print("Vertex\tDistance from Source")
    for i, dist in enumerate(distances):
        print(f"{i}\t{dist}")

# Example usage:
if __name__ == "__main__":
    g = Graph(6)

    g.add_edge(0, 1, 2)
    g.add_edge(0, 3, 1)
    g.add_edge(1, 2, 4)
    g.add_edge(1, 3, 3)
    g.add_edge(2, 4, 5)
    g.add_edge(3, 5, 7)
    g.add_edge(4, 5, 4)

    source_vertex = 0

    shortest_distances = g.dijkstra(source_vertex)
    print_solution(shortest_distances)
