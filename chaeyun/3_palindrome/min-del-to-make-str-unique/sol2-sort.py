# Sorting Approach
class Solution:
    def minDeletions(self, s: str) -> int:
        cnt = Counter(s)
        deletions = 0
        used_frequencies = set()
        
        sorted_freqs = sorted(cnt.values(), reverse=True)
        
        for freq in sorted_freqs:
            if freq not in used_frequencies:  # Early exit condition
                used_frequencies.add(freq)
                continue  

            while freq > 0 and freq in used_frequencies:
                freq -= 1
                deletions += 1

            used_frequencies.add(freq)
            
        return deletions