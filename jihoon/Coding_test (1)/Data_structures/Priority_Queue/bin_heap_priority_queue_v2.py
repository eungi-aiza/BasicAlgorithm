import heapq

class PriorityQueue:
    def __init__(self):
        self.heap = []

    def put(self, item, priority):
        heapq.heappush(self.heap, (priority, item))

    def get(self):
        return heapq.heappop(self.heap)[1]

pq = PriorityQueue()
pq.put("A", 3)
pq.put("B", 1)
pq.put("C", 2)
print(pq.get()) # B
print(pq.get()) # C
print(pq.get()) # A