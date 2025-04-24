#시간도 없고 기업은행 대비 파이썬 연습도 할 겸... 파이썬으로 대충 품 우선순위 큐 이런거 사용하지 않고

N, M = map(int, input().split())
mile = []
for _ in range(N):
    P, L = map(int, input().split())
    people = list(map(int, input().split()))
    
    people.sort(reverse=True)
    if P < L:
        mile.append(1)
    else:
        mile.append(people[L - 1])

mile.sort()

cnt = 0
for cost in mile:
    if M >= cost:
        M -= cost
        cnt += 1
    else:
        break

print(cnt)
