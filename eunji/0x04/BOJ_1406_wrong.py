import sys
sys.stdout = open('output.txt', 'w')
sys.stdin = open("input.txt", "r")

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

sent = list(input())
start = Node(None)
ans = start
for s in range(len(sent)):
    start.next = Node(sent[s])
    temp = start
    start = start.next
    start.prev = temp

# print(start.prev.data)
M = int(input())

for i in range(M):
    inputs = list(sys.stdin.readline().split())
    if len(inputs) == 1:
        order = inputs[0]
        if order == 'L' and start.prev!= None:
            start = start.prev
        elif order == 'D' and start.next != None:
            start = start.next
        elif order == 'B' and start.prev != None:
            temp = start.next
            start = start.prev
            start.next = temp
    if len(inputs) == 2:
        order = inputs[0]; target = inputs[1]
        if order == 'P':
            temp = start.next
            add = Node(target)
            start.next = add
            add.next = temp
            add.prev = start
            if temp: temp.prev = add
            start = start.next
# print(sent)
while ans.next:
    ans = ans.next
    print(ans.data, end="")
    

sys.stdout.close()