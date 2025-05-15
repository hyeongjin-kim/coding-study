import sys
import bisect

input = sys.stdin.readline

N = int(input())
numbers = list(map(int, input().split()))
numbers.sort()

good_count = 0

for idx in range(N):
    target = numbers[idx]
    for jdx in range(N):
        if idx == jdx:
            continue
        remain = target - numbers[jdx]

        # 같은 값이 여러 개 있을 수 있으므로, 구간 전부 확인
        l = bisect.bisect_left(numbers, remain)
        r = bisect.bisect_right(numbers, remain)

        for i in range(l, r):
            if i != idx and i != jdx:
                good_count += 1
                break  # 하나라도 찾으면 "좋은 수"
        else:
            continue
        break  # 찾았으면 다음 target으로 넘어감

print(good_count)
