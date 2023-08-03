class Node:
    def __init__(self, value):
        self.val = value
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
        self.count = 0

    def empty(self):
        return self.count == 0

    def push(self, val):
        newNode = Node(val)
        if self.empty():
            self.front = newNode
        else:
            self.rear.next = newNode
        self.rear = newNode
        self.count += 1

    def getFront(self):
        if self.empty():
            print("Error: Queue is empty")
            return None
        return self.front.val

    def pop(self):
        if self.empty():
            print("Error: Queue is empty")
            return
        self.front = self.front.next
        if not self.front:
            self.rear = None
        self.count -= 1

if __name__ == "__main__":
    queue = Queue()

    for i in range(1, 11):
        queue.push(i)

    while not queue.empty():
        print(queue.getFront(), end=" ")
        queue.pop()

    print()
