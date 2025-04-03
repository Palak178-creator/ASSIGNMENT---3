longest-consecutive-sequence#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end()); // Store all elements in a set
        int longestStreak = 0;

        for (int num : numSet) { // Iterate through set
            if (numSet.find(num - 1) == numSet.end()) { // Check if it's the start of a sequence
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) { // Count consecutive elements
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

