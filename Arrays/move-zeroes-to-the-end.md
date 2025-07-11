## 🧱 Leetcode 283: Move Zeroes

### 📘 Problem:
Given an integer array `nums`, move all `0`'s to the end of it while maintaining the **relative order** of the non-zero elements.

> You must do this in-place without making a copy of the array.

---

### 💡 Approach: Two-Pointer Technique

- Use a variable `lastNonZeroIndex` to keep track of the position where the next non-zero element should go.
- Traverse the array:
  - If the current element is not zero, place it at `lastNonZeroIndex` and increment `lastNonZeroIndex`.
- After placing all non-zero elements, fill the remaining part of the array with zeros.

---

### ✅ Code Logic:
```cpp
void moveZeroes(vector<int>& nums) {
    int lastNonZeroIndex = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroIndex++] = nums[i];
        }
    }
    for (int i = lastNonZeroIndex; i < nums.size(); i++) {
        nums[i] = 0;
    }
}
