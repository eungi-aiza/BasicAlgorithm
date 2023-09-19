class Queue:
    def __init__(self):
        self.data = []
        self.size = 0

    def push(self, val):
        self.data.append(val)
        self.size += 1

    def pop(self):
        if self.empty():
            print("Queue is empty!")
            return
        self.data.pop(0)
        self.size -= 1

    def front(self):
        if self.empty():
            print("Queue is empty!")
            return None
        return self.data[0]

    def back(self):
        if self.empty():
            print("Queue is empty!")
            return None
        return self.data[-1]

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
    
    print("Front element:", q.front())
    print("Rear element:", q.back())
    print("Queue size:", q.get_size())
    
    q.pop()
    
    print("Front element after pop:", q.front())
    print("Rear element after pop:", q.back())
    print("Queue size after pop:", q.get_size())
