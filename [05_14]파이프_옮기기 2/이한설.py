import sys
input = sys.stdin.readline


N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

# dp_w[i][j]: (i,j)를 우측 끝으로 하는 가로 파이프 경우의 수
# dp_h[i][j]: (i,j)를 하단 끝으로 하는 세로 파이프 경우의 수
# dp_d[i][j]: (i,j)를 대각선 끝으로 하는 대각선 파이프 경우의 수
dp_w = [[0]*N for _ in range(N)]
dp_h = [[0]*N for _ in range(N)]
dp_d = [[0]*N for _ in range(N)]

dp_h[0][1] = 1

for idx in range(N):
    for jdx in range(N):
        if board[idx][jdx] == 1:
            continue

        # 가로 → 오른쪽, 대각
        if j+1 < N and board[idx][jdx+1] == 0:
            dp_w[i][j+1] += dp_w[idx][jdx] + dp_d[idx][jdx]
        # 세로 → 아래,  대각
        if i+1 < N and board[idx+1][jdx] == 0:
            dp_h[i+1][j] += dp_h[idx][jdx] + dp_d[idx][jdx]
        # 대각 → 오른쪽, 아래, 대각선
        if i+1 < N and j+1 < N and board[idx][jdx+1] == 0 \
           and board[idx+1][jdx] == 0 and board[idx+1][jdx+1] == 0:
            dp_d[idx+1][jdx+1] += dp_h[idx][jdx] + dp_v[idx][jdx] + dp_d[idx][jdx]

# 최종 목표 (N-1, N-1) 에 올 수 있는 모든 방향 합
result = dp_h[N-1][N-1] + dp_v[N-1][N-1] + dp_d[N-1][N-1]
print(result)
