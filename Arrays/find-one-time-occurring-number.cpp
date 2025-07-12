// Leetcode 136 : Single Number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto it : freq) {
            if (it.second == 1)
                return it.first;
        }
        return -1;
    }
};


// The optimal solution of this problem is solved using bit manipulation
// This is an alternative way to solve the question using unordered_map
