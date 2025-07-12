## ➕ Leetcode 1: Two Sum

### 📘 Problem:
Given an array of integers `nums` and an integer `target`, return **indices** of the two numbers such that they add up to `target`.

> You may assume that each input would have **exactly one solution**, and you may not use the same element twice.  
> You can return the answer in any order.

---

### 💡 Approach: Hash Map for Complement Lookup

- Use an `unordered_map` to store `{value → index}` as you iterate.
- For each number in the array:
  - Compute the `difference = target - number`.
  - If this difference already exists in the map, you've found the two numbers.
- Return the stored index of the difference and the current index.

---

### ✅ Code:
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++) {
        int number = nums[i];
        int difference = target - number;
        if (mpp.find(difference) != mpp.end()) {
            return {mpp[difference], i};
        }
        mpp[number] = i;
    }
    return {-1}; // fallback if no solution exists (based on constraints, this line won't be reached)
}
