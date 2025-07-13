## Leetcode 169 : Majority Element

### Problem Statement
Given an array `nums` of size `n`, return the **majority element**.

The majority element is the element that appears **more than ⌊n / 2⌋ times**.  
You may assume that the majority element always exists in the array.

---

### Example 1
**Input**:  
`nums = [3, 2, 3]`  
**Output**: `3`

### Example 2
**Input**:  
`nums = [2,2,1,1,1,2,2]`  
**Output**: `2`

---

### 🔍 Approach: Boyer-Moore Voting Algorithm

This algorithm works on the principle of "canceling out" non-majority elements:

1. Start with a `count = 0` and no `candidate`.
2. Iterate through the array:
   - If `count == 0`, set the `candidate` to the current number.
   - If the current number is the same as `candidate`, increment `count`.
   - Otherwise, decrement `count`.
3. At the end, the `candidate` will be the majority element.

---

### ✅ Code (C++)
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};
