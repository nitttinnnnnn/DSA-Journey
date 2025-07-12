## 🔍 Leetcode 136: Single Number

### 📘 Problem:
Given a non-empty integer array `nums`, where **every element appears exactly twice except for one**, find and return the element that appears only once.

> You must implement a solution with **linear runtime complexity**.

---

### 💡 Approach: Hash Map (Frequency Count)

- Use an `unordered_map` (hash map) to store the **frequency** of each element.
- Loop through the array once to build the frequency map.
- Loop through the map to find the element that appears **only once**.

---

### ✅ Code:
```cpp
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
