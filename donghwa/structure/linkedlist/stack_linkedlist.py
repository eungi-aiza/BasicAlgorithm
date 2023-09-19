class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.top = None

    def is_empty(self):
        return self.top is None

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.top
        self.top = new_node

    def pop(self):
        if self.is_empty():
            print("Stack is empty")
            return None
        data = self.top.data
        self.top = self.top.next
        return data

    def peek(self):
        if self.is_empty():
            print("Stack is empty")
            return None
        return self.top.data


# Example usage
stack = Stack()

stack.push(1)
stack.push(2)
stack.push(3)

print("Top:", stack.peek())

stack.pop()
print("Top after pop:", stack.peek())
