## 🔄 Leetcode 189: Rotate Array

### 📘 Problem:
Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

> You must rotate the array **in-place** with **O(1)** extra memory.

---

### 💡 Approach: Reverse Trick (Three Reversals)

To rotate the array to the right by `k` steps:
1. Reverse the entire array.
2. Reverse the first `k` elements.
3. Reverse the remaining `n - k` elements.

This effectively rotates the array by `k` places.

---

### ✅ Code Logic:
```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // To handle cases where k > n

    reverse(nums.begin(), nums.end());          // Step 1
    reverse(nums.begin(), nums.begin() + k);    // Step 2
    reverse(nums.begin() + k, nums.end());      // Step 3
}
