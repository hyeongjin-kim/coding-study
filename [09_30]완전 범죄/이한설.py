def solution(info, n, m):
    Length = len(info)

    dp = [[[-1] * m for _ in range(n)] for _ in range(Length + 1)] # 3차원으로 잡고 세로 A, 가로 B, 차원(첫번째 인덱스) 물건의 인덱스
    dp[0][0][0] = 0 

    for idx, (n_w, m_w) in enumerate(info):
        for n_idx in range(n):
            for m_idx in range(m):
                if dp[idx][n_idx][m_idx] == -1:  
                    continue

                n_trace = n_idx + n_w
                if n_trace < n:
                    dp[idx+1][n_trace][m_idx] = max(dp[idx+1][n_trace][m_idx],
                                               dp[idx][n_idx][m_idx] + 1)

                m_trace = m_idx + m_w
                if m_trace < m:
                    dp[idx+1][n_idx][m_trace] = max(dp[idx+1][n_idx][m_trace],
                                               dp[idx][n_idx][m_idx] + 1)

    answer = -1
    for n_idx in range(n):
        for m_idx in range(m):
            if dp[Length][n_idx][m_idx] == Length: 
                if answer == -1 or n_idx < answer:
                    answer = n_idx
                    
    return answer 
