#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    int minDeletions(std::string s) {
        std::unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }
        
        std::vector<int> sorted_freqs;
        for (const auto& pair : cnt) {
            sorted_freqs.push_back(pair.second);
        }
        std::sort(sorted_freqs.begin(), sorted_freqs.end(), std::greater<int>());
        
        int deletions = 0;
        std::unordered_set<int> used_frequencies;
        
        for (int freq : sorted_freqs) {
            if (used_frequencies.find(freq) == used_frequencies.end()) {
                used_frequencies.insert(freq);
                continue;
            }
            
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
