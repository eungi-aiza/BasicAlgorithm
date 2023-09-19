from collections import Counter
import heapq
# Heap / Priority Queue Approach
class Solution:
    def minDeletions(self, s: str) -> int:
        cnt = Counter(s)
        deletions = 0
        used_frequencies = set()
        
        heap = list(cnt.values())
        heapq.heapify(heap)
        
        while heap:
            freq = heapq.heappop(heap)
            while freq > 0 and freq in used_frequencies:
                freq -= 1
                deletions += 1
            used_frequencies.add(freq)
            
        return deletions