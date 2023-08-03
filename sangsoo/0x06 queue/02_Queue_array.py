class Queue:
    MAX_SIZE = 1024

    def __init__(self):
        self.data = [None] * self.MAX_SIZE
        self.frontIdx = 0
        self.rearIdx = -1
        self.count = 0

    def empty(self):
        return self.count == 0

    def full(self):
        return self.count == self.MAX_SIZE

    def push(self, val):
        if self.full():
            print("Error: Queue is full")
            return
        self.rearIdx = (self.rearIdx + 1) % self.MAX_SIZE
        self.data[self.rearIdx] = val
        self.count += 1

    def front(self):
        if self.empty():
            print("Error: Queue is empty")
            return None
        return self.data[self.frontIdx]

    def pop(self):
        if self.empty():
            print("Error: Queue is empty")
            return
        self.frontIdx = (self.frontIdx + 1) % self.MAX_SIZE
        self.count -= 1

    def size(self):
        return self.count


if __name__ == "__main__":
    queue = Queue()

    for i in range(1, 11):
        queue.push(i)

    while not queue.empty():
        print(queue.front(), end=" ")
        queue.pop()

    print()
