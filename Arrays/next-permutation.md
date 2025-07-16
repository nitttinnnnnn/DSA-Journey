## Leetcode 31: Next Permutation

### 🧾 Problem Statement

A **permutation** of an array of integers is an arrangement of its members into a sequence or linear order.

The **next permutation** of an array of integers is the next lexicographically greater permutation.  
If such an arrangement is not possible (i.e., the array is in descending order), it must be rearranged to the **lowest possible order** (i.e., sorted in ascending order).

You must implement this **in-place** and use **only constant extra memory**.

---

### 🔍 Examples

**Example 1**  
**Input**: `nums = [1, 2, 3]`  
**Output**: `[1, 3, 2]`

**Example 2**  
**Input**: `nums = [3, 2, 1]`  
**Output**: `[1, 2, 3]`

**Example 3**  
**Input**: `nums = [1, 1, 5]`  
**Output**: `[1, 5, 1]`

---

### 💡 Optimal Approach (In-place Algorithm)

To generate the next permutation:

1. Traverse the array from the end and find the first element that violates the descending order, i.e., `nums[i] < nums[i + 1]`.
2. If such an element is not found, reverse the entire array.
3. Otherwise, find the element just larger than `nums[i]` from the end of the array, and swap both.
4. Finally, reverse the subarray from `i + 1` to the end to get the next permutation.

---

### ✅ C++ Code

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // Step 1: Find first decreasing element from the end
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: If not found, reverse entire array
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find next greater element from the end and swap
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 4: Reverse the suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};
