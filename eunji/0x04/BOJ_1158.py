N, K = map(int, input().split())

class Node:
    def __init__(self, data):
        self.data = data
        self.next = next
        
curr = Node(1)
start = curr
for i in range(2, N+1):
    curr.next = Node(i)
    curr = curr.next
curr.next = start

print('<', end="")
while curr.next:
    for i in range(K-1):
        curr = curr.next
    if curr.next == curr:
        print(curr.next.data, end="")
        print(">")
        break
    print(curr.next.data, end=", ")
    temp = curr.next.next
    curr.next = temp