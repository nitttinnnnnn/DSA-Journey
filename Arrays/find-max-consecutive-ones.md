## 🔢 Leetcode 485: Max Consecutive Ones

### 📘 Problem:
Given a binary array `nums`, return the **maximum number of consecutive 1's** in the array.

> You must solve it in **linear time** and with **constant space**.

---

### 💡 Approach: Linear Scan with Counter

- Traverse the array while maintaining:
  - `len`: the current streak of consecutive 1s
  - `maxLen`: the longest streak found so far
- If the current number is `1`, increment `len` and update `maxLen`.
- If it’s `0`, reset `len` to 0.

---

### ✅ Code:
```cpp
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
