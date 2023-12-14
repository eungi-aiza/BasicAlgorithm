"""
## 1260 BFS_DFS
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

PseudoCode

bfs(V, E, R) {  # V : 정점 집합, E : 간선 집합, R : 시작 정점
    for each v ∈ V - {R}
        visited[v] <- NO;
    visited[R] <- YES;  # 시작 정점 R을 방문 했다고 표시한다.
    enqueue(Q, R);  # 큐 맨 뒤에 시작 정점 R을 추가한다.
    while (Q ≠ ?) {
        u <- dequeue(Q);  # 큐 맨 앞쪽의 요소를 삭제한다.
        for each v ∈ E(u)  # E(u) : 정점 u의 인접 정점 집합.(정점 번호를 오름차순으로 방문한다)
            if (visited[v] = NO) then {
                visited[v] <- YES;  # 정점 v를 방문 했다고 표시한다.
                enqueue(Q, v);  # 큐 맨 뒤에 정점 v를 추가한다.
            }
    }
}


dfs(V, E, R) {  # V : 정점 집합, E : 간선 집합, R : 시작 정점
    visited[R] <- YES;  # 시작 정점 R을 방문 했다고 표시한다.
    for each x ∈ E(R)  # E(R) : 정점 R의 인접 정점 집합.(정점 번호를 오름차순으로 방문한다)
        if (visited[x] = NO) then dfs(V, E, x);
}

"""

# import sys
# sys.setrecursionlimit(10**6)
# input = sys.stdin.readline

from collections import deque
N, M, V = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited_1 = [0] * (N+1)

for i in range(M) :
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
    
for i in range(N+1) : graph[i].sort()
    
## BFS
def bfs(graph, visited, start) :
    queue = deque([start])
    visited[start] = True
    while queue :
        v = queue.popleft()
        print(v, end=' ')
        for nei in graph[v] :
            if not visited[nei] :
                visited[nei] = True
                queue.append(nei)

visited_2 = [0]* (N+1)                
def dfs(graph, visited, V) :
    visited[V] = True
    print(V, end=' ')
    for nei in graph[V] :
        if not visited[nei] :
            dfs(graph, visited, nei)
            
dfs(graph, visited_2, V)
print()
bfs(graph, visited_1, V) 