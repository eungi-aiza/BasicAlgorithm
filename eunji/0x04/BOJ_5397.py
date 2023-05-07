import sys

# sys.stdout = open('output.txt', 'w')
# sys.stdin = open("input.txt", "r")

class Node:
    def __init__(self, data, prev=None, next=None):
        self.data = data
        self.prev = prev
        self.next = next

N = int(input())
for i in range(N):
  inputs = list(input().strip())
  curr = Node(None)
  start = curr
  for j in range(len(inputs)):
    if (inputs[j] == '-') and (curr.prev != None):
      temp = curr.next
      curr = curr.prev
      curr.next = temp
      if temp: temp.prev = curr
    elif (inputs[j] == '<') and (curr.prev != None):
      curr = curr.prev
    elif (inputs[j] == '>') and (curr.next != None):
      curr = curr.next
    elif (inputs[j] != '<') and (inputs[j] != '-') and (inputs[j] != '>'):
      temp = curr.next
      new_node = Node(inputs[j])
      curr.next = new_node
      new_node.next = temp
      new_node.prev = curr
      if temp: temp.prev = new_node
      curr = curr.next
     
    
  while start.next:
      start = start.next
      print(start.data, end="")
  print()
        
      
# sys.stdout.close()
  

