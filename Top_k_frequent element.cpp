Top K frequent 
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;  // Store frequency of each number
        
        // Step 1: Count frequency of each number
        for (int num : nums) {
            freqMap[num]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);  // Buckets for frequencies

        // Step 2: Fill buckets where index represents frequency
        for (auto& [num, freq] : freqMap) {
            buckets[freq].push_back(num);
        }

        // Step 3: Collect top K frequent elements from the highest frequency
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) return result;  // Stop when we have k elements
            }
        }

        return result;
    }
};
