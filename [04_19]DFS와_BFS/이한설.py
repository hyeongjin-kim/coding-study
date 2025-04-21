from collections import defaultdict, deque

N, M, V = map(int, input().split())
graph = defaultdict(list)

for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

visited = [False] * (N + 1)

def dfs(node):
    visited[node] = True
    print(node, end=' ')
    for u in sorted(graph[node]):
        if not visited[u]:
            dfs(u)

def bfs(node):
    visited2 = [False] * (N + 1)
    queue = deque([node])
    visited2[node] = True
    while queue:
        u = queue.popleft()
        print(u, end = ' ')
        for v in sorted(graph[u]):
            if not visited2[v]:
                visited2[v] = True
                queue.append(v)

dfs(V)
print()
bfs(V)
