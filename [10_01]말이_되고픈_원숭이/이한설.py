from collections import deque

N = int(input())
W, H = map(int, input().split())

directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
horse_dirs = [[2, 1], [2, -1], [1, 2], [1, -2],
              [-2, 1], [-2, -1], [-1, 2], [-1, -2]]

board = [list(map(int, input().split())) for _ in range(H)]
visited = [[[0] * (N + 1) for _ in range(W)] for _ in range(H)]

q = deque()
q.append([0, 0, 0])
visited[0][0][0] = 1

while q:
    cx, cy, cnt = q.popleft()
    
    if cx == H - 1 and cy == W - 1:
        print(visited[cx][cy][cnt] - 1)
        break

    for dx, dy in directions:
        nx, ny = cx + dx, cy + dy
        if 0 <= nx < H and 0 <= ny < W and board[nx][ny] == 0 and not visited[nx][ny][cnt]:
            visited[nx][ny][cnt] = visited[cx][cy][cnt] + 1
            q.append([nx, ny, cnt])

    if cnt < N:
        for dx, dy in horse_dirs:
            nx, ny = cx + dx, cy + dy
            if 0 <= nx < H and 0 <= ny < W and board[nx][ny] == 0 and not visited[nx][ny][cnt + 1]:
                visited[nx][ny][cnt + 1] = visited[cx][cy][cnt] + 1
                q.append([nx, ny, cnt + 1])

else:
    print(-1)
