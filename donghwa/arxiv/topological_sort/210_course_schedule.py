from collections import defaultdict, deque

def findOrder(numCourses, prerequisites):
    # Build a directed graph
    graph = defaultdict(list)
    in_degree = [0] * numCourses
    
    for course, prereq in prerequisites:
        graph[course].append(prereq)  # Reverse the edges
        in_degree[prereq] += 1
    
    # Initialize a queue with courses having no prerequisites
    queue = deque()
    for i in range(numCourses):
        if in_degree[i] == 0:
            queue.append(i)
    
    order = []
    
    # Perform topological sort
    while queue:
        course = queue.popleft()
        order.append(course)
        for neighbor in graph[course]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)
    
    # Check if all courses can be taken
    if len(order) == numCourses:
        return order[::-1]  # Reverse the order to get the correct result
    else:
        return []

# Test Cases
print(findOrder(2, [[1, 0]]))  # Output: [0, 1]
print(findOrder(4, [[1, 0], [2, 0], [3, 1], [3, 2]]))  # Output: [0, 2, 1, 3]
print(findOrder(1, []))  # Output: [0]
