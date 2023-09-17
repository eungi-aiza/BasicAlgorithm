class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def front(self):
        if self.head:
            return self.head.data
        else:
            print("List is empty!")
            return -1

    def back(self):
        if self.tail:
            return self.tail.data
        else:
            print("List is empty!")
            return -1

    def size(self):
        return self.size

    def empty(self):
        return self.size == 0

    def push(self, x):
        new_node = Node(x)
        if self.tail is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.size += 1

    def pop(self):
        if self.size > 0:
            if self.head:
                tmp = self.head.next
                del self.head
                self.head = tmp
                self.size -= 1
                if self.size == 0:
                    self.tail = None
