def minimal_key_length(v):
    """
    벡터 v의 최소 키 길이(k)를 반환.
    k 는 v[i] == v[i % k] 가 모든 i에 성립하도록 하는 가장 작은 k.
    """
    n = len(v)
    # 1) π 함수 계산
    pi = [0] * n
    j = 0
    for i in range(1, n):
        while j > 0 and v[i] != v[j]:
            j = pi[j - 1]
        if v[i] == v[j]:
            j += 1
        pi[i] = j
    # 2) 최소 키 길이
    k = n - pi[-1]
    return k

enc_password = input().strip()
hint         = input().strip()
N, NH = len(enc_password), len(hint)

what = []
for idx in range(N - NH + 1):
    window = []
    for jdx in range(NH):
        diff = (ord(enc_password[idx + jdx]) - ord(hint[jdx])) % 26
        window.append(diff)
    what.append(window)

min_value = float('inf')
min_idx   = 0
for idx, w in enumerate(what):
    klen = minimal_key_length(w)
    if klen < min_value:
        min_value = klen
        min_idx   = idx

key_nums = what[min_idx]

key = [chr(ord('a') + num) for num in key_nums]

k = min_idx % min_value

for _ in range(k, min_value):
    key.pop(0)

real_key = key[:min_value]

for i, ch in enumerate(enc_password):
    k = real_key[i % min_value]
    plain = chr((ord(ch) - ord(k)) % 26 + ord('a'))
    print(plain, end='')
