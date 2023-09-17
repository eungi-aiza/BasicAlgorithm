# Import heapq module for priority queue
import heapq

# Define a function for the Dijkstra algorithm
def dijkstra(graph, start):
    # Initialize a dictionary to store the distances from the start node
    distances = {node: float('inf') for node in graph}
    # Set the distance of the start node to zero
    distances[start] = 0
    # Initialize an empty priority queue to store the nodes with their distances
    queue = []
    # Push the start node with its distance to the queue
    heapq.heappush(queue, (distances[start], start))
    # Loop until the queue is empty
    while queue:
        # Pop the node with the smallest distance from the queue
        current_distance, current_node = heapq.heappop(queue)
        # If the current distance is larger than the stored distance, skip this node
        if current_distance > distances[current_node]:
            continue
        # For each neighbor and weight of the current node
        for neighbor, weight in graph[current_node].items():
            # Calculate the distance to the neighbor through the current node
            distance = current_distance + weight
            # If the distance is smaller than the stored distance, update it and push it to the queue
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))
    # Return the dictionary of distances
    return distances

# Define a graph as a dictionary of dictionaries
graph = {
    'A': {'B': 10, 'C': 3},
    'B': {'C': 1, 'D': 2},
    'C': {'B': 4, 'D': 8, 'E': 2},
    'D': {'E': 7},
    'E': {'D': 9}
}

# Call the function with the graph and a start node
print(dijkstra(graph, 'A'))