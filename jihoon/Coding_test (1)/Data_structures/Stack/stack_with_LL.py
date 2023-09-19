class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None

    def isEmpty(self):
        return self.top == None

    def push(self, data):
        node = Node(data)
        node.next = self.top
        self.top = node
        print(f"{data} pushed to stack.")

    def pop(self):
        if self.isEmpty():
            return -1
        temp = self.top
        self.top = self.top.next
        popped = temp.data
        del temp
        return popped

    def peek(self):
        if self.isEmpty():
            return -1
        return self.top.data

# Example usage
s = Stack()

s.push(10)
s.push(20)
s.push(30)

print(f"{s.pop()} popped from stack.")

print(f"Top element is {s.peek()}.")
