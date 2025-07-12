## ⚡ Leetcode 136: Single Number (XOR Solution)

### 📘 Problem:
Given a **non-empty** array of integers `nums`, where **every element appears exactly twice except for one**, return the single element that appears only once.

> You must implement a solution with **linear runtime complexity** and **constant extra space**.

---

### 💡 Approach: Bit Manipulation using XOR

- XOR has useful properties:
  - `a ^ a = 0`
  - `a ^ 0 = a`
  - XOR is **commutative** and **associative**
- If we XOR all numbers together, duplicate numbers cancel out and we're left with the number that appears once.

---

### ✅ Code:
```cpp
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}
