class PriorityQueue:
    def __init__(self):
        self.heap = []

    def _heapify(self, i):
        # Restore the heap invariant for the subtree rooted at i
        n = len(self.heap)
        left = 2 * i + 1
        right = 2 * i + 2
        smallest = i
        if left < n and self.heap[left][0] < self.heap[smallest][0]:
            smallest = left
        if right < n and self.heap[right][0] < self.heap[smallest][0]:
            smallest = right
        if smallest != i:
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self._heapify(smallest)

    def _siftup(self, i):
        # Move the element at i up to its proper position
        parent = (i - 1) // 2
        while i > 0 and self.heap[i][0] < self.heap[parent][0]:
            self.heap[i], self.heap[parent] = self.heap[parent], self.heap[i]
            i = parent
            parent = (i - 1) // 2

    def _siftdown(self, i):
        # Move the element at i down to its proper position
        n = len(self.heap)
        while True:
            left = 2 * i + 1
            right = 2 * i + 2
            smallest = i
            if left < n and self.heap[left][0] < self.heap[smallest][0]:
                smallest = left
            if right < n and self.heap[right][0] < self.heap[smallest][0]:
                smallest = right
            if smallest == i:
                break
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            i = smallest

    def put(self, item, priority):
        # Add a new item with the given priority to the heap
        self.heap.append((priority, item))
        self._siftup(len(self.heap) - 1)

    def get(self):
        # Remove and return the item with the lowest priority from the heap
        if not self.heap:
            return None
        item = self.heap[0][1]
        last = self.heap.pop()
        if self.heap:
            self.heap[0] = last
            self._heapify(0)
        return item

pq = PriorityQueue()
pq.put("A", 3)
pq.put("B", 1)
pq.put("C", 2)
print(pq.get()) # B
print(pq.get()) # C
print(pq.get()) # A