"""
## 1260 BFS_DFS
�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�.

PseudoCode

bfs(V, E, R) {  # V : ���� ����, E : ���� ����, R : ���� ����
    for each v �� V - {R}
        visited[v] <- NO;
    visited[R] <- YES;  # ���� ���� R�� �湮 �ߴٰ� ǥ���Ѵ�.
    enqueue(Q, R);  # ť �� �ڿ� ���� ���� R�� �߰��Ѵ�.
    while (Q �� ?) {
        u <- dequeue(Q);  # ť �� ������ ��Ҹ� �����Ѵ�.
        for each v �� E(u)  # E(u) : ���� u�� ���� ���� ����.(���� ��ȣ�� ������������ �湮�Ѵ�)
            if (visited[v] = NO) then {
                visited[v] <- YES;  # ���� v�� �湮 �ߴٰ� ǥ���Ѵ�.
                enqueue(Q, v);  # ť �� �ڿ� ���� v�� �߰��Ѵ�.
            }
    }
}


dfs(V, E, R) {  # V : ���� ����, E : ���� ����, R : ���� ����
    visited[R] <- YES;  # ���� ���� R�� �湮 �ߴٰ� ǥ���Ѵ�.
    for each x �� E(R)  # E(R) : ���� R�� ���� ���� ����.(���� ��ȣ�� ������������ �湮�Ѵ�)
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