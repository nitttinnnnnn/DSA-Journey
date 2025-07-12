## ➕ Two Sum (Sorted with Two-Pointer)

### 📘 Problem:
Given an **unsorted array** of integers `nums` and an integer `target`, determine if there exist **two distinct elements** whose sum equals the target.

> Return `"YES"` if such a pair exists, otherwise return `"NO"`.

---

### 💡 Approach: Sort + Two Pointer

1. First, **sort the array** in non-decreasing order.
2. Use two pointers:
   - `l` starting from the beginning
   - `r` starting from the end
3. While `l < r`:
   - Compute `sum = nums[l] + nums[r]`
   - If `sum == target`: return `"YES"`
   - If `sum < target`: increment `l` (to increase sum)
   - If `sum > target`: decrement `r` (to decrease sum)
4. If no such pair is found, return `"NO"`.

---

### ✅ Code:
```cpp
// Two-Sum function that returns "YES" if a valid pair is found, otherwise "NO"
// Time Complexity: O(n log n) for sorting + O(n) for two-pointer traversal

String twoSum(vector<int> nums, int target) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    sort(nums.begin(), nums.end());  // Ensure sorted input for two-pointer
    while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) {
            return "YES";
        } else if (sum > target) {
            r--;
        } else {
            l++;
        }
    }
    return "NO";
}
