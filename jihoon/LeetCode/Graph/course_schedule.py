class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = collections.defaultdict(list)
        for course, prereq in prerequisites:
            graph[course].append(prereq)

        traced = set()
        visited = set()

        def dfs(i):
            # If graph is cyclic, return false
            if i in traced:
                return False
            # If already visited, return true
            if i in visited:
                return True
            traced.add(i)
            for y in graph[i]:
                if not dfs(y):
                    return False
            # Remove node when finsihed with search
            traced.remove(i)
            # Add node to visited when search finished
            visited.add(i)
            return True

        # Run DFS to find cyclic graph structure
        for x in list(graph):
            if not dfs(x):
                return False
        return True