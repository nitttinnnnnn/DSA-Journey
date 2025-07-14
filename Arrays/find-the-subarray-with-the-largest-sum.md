## Leetcode 53 : Maximum Subarray

### Problem Statement
Given an integer array `nums`, find the **contiguous subarray** (containing at least one number) which has the **largest sum**, and return its sum.

---

### 🔍 Example 1
**Input**:  
`nums = [-2,1,-3,4,-1,2,1,-5,4]`  
**Output**: `6`  
**Explanation**: `[4, -1, 2, 1]` has the largest sum = `6`.

---

### ✅ Approach: Kadane’s Algorithm

We iterate through the array while keeping track of:
- `sum`: the current subarray sum
- `maxSum`: the maximum sum seen so far

**Steps**:
1. Initialize `sum = 0` and `maxSum = INT_MIN` (to handle all-negative arrays).
2. For each element `nums[i]`:
   - If `sum` is negative, reset it to `0` (because starting fresh is better than continuing with a negative sum).
   - Add `nums[i]` to `sum`.
   - Update `maxSum` with the maximum of `maxSum` and `sum`.

---

### 📌 Code (C++)
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            if (sum < 0) {
                sum = 0;
            }
            sum += nums[i];
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};
