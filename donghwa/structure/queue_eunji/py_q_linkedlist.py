class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0

    def push(self, data):
        new_node = Node(data)
        if self.rear is None:
            self.front = self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node
        self.size += 1

    def pop(self):
        if self.empty():
            print("Queue is empty!")
            return
        temp = self.front
        self.front = self.front.next
        if self.front is None:
            self.rear = None
        del temp
        self.size -= 1

    def get_front(self):
        if self.empty():
            print("Queue is empty!")
            return None
        return self.front.data

    def get_back(self):
        if self.empty():
            print("Queue is empty!")
            return None
        return self.rear.data

    def empty(self):
        return self.size == 0

    def get_size(self):
        return self.size


# Testing the Queue class
if __name__ == "__main__":
    q = Queue()
    
    q.push(1)
    q.push(2)
    q.push(3)
    q.push(4)

    print("Front element:", q.get_front())
    print("Rear element:", q.get_back())
    print("Queue size:", q.get_size())

    q.pop()

    print("Front element after pop:", q.get_front())
    print("Rear element after pop:", q.get_back())
    print("Queue size after pop:", q.get_size())
