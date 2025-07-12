// Leetcode 485 : Max Consecutive Ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                len++;
                maxLen = max(maxLen, len);
            } else {
                len = 0;
            }
        }
        return maxLen;
    }
};
