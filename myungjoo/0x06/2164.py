from collections import deque

N = int(input())
card = deque([])

for i in range(1,N+1):
    card.append(i)

#print(card)
while len(card) > 1:
    a = card.popleft()
    #print(card)
    card.append(card[0])
    #print(card)
    card.popleft()
    #print(card)
    
print(card[-1])