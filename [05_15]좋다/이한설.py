import sys
input = sys.stdin.readline

N = int(input())
numbers = list(map(int, input().split()))
numbers.sort()

good_count = 0

for idx in range(N):
    target = numbers[idx]
    left = 0
    right = N - 1

    while left < right:
        if left == idx:
            left += 1
            continue
        if right == idx:
            right -= 1
            continue

        sum_two = numbers[left] + numbers[right]
        if sum_two == target:
            good_count += 1
            break
        elif sum_two < target:
            left += 1
        else:
            right -= 1

print(good_count)
