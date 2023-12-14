#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>

class Solution {
public:
    int minDeletions(std::string s) {
        std::unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }
        
        int deletions = 0;
        std::unordered_set<int> used_frequencies;
        
        // Create a min heap (note the difference in C++ for this)
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
        for (const auto& pair : cnt) {
            heap.push(pair.second);
        }
        
        while (!heap.empty()) {
            int freq = heap.top();
            heap.pop();

            while (freq > 0 && used_frequencies.find(freq) != used_frequencies.end()) {
                freq--;
                deletions++;
            }

            if (freq > 0) {
                used_frequencies.insert(freq);
            }
        }
        
        return deletions;
    }
};
