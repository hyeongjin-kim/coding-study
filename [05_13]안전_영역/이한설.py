from collections import deque

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

max_value = 0
directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def bfs(board, threshold):
    visited = [[0] * N for _ in range(N)]
    q = deque()
    cnt = 1

    for idx in range(N):
        for jdx in range(N):
            if board[idx][jdx] > threshold and visited[idx][jdx] == 0:
                q.append([idx, jdx])
                visited[idx][jdx] = cnt
                while q:
                    x, y = q.popleft()
                    for dx, dy in directions:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == 0 and board[nx][ny] > threshold:
                            visited[nx][ny] = cnt
                            q.append([nx, ny])
                cnt += 1

    return cnt - 1

for idx in range(N):
    for jdx in range(N):
        if board[idx][jdx] > max_value:
            max_value = board[idx][jdx]

answer = 0;
for idx in range(1, max_value + 1):
    answer = max(answer, bfs(board, idx))

print(answer)
