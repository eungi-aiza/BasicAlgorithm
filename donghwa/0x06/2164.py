import sys
N = int(sys.stdin.readline().strip())
queue = list(range(1,N+1))

head, tail = 0, N-1
while(head-tail != 1):
    head += 1
    if (head-tail == 1): break
    queue.append(queue[head])
    head += 1
    tail += 1

print(queue[tail])