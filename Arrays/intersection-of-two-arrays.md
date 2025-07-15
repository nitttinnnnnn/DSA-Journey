## Leetcode 349: Intersection of Two Arrays

### 🧾 Problem Statement

Given two integer arrays `nums1` and `nums2`, return an array of their intersection.  
Each element in the result **must be unique**, and you may return the result in **any order**.

---

### 🔍 Examples

**Example 1**  
**Input**:  
`nums1 = [1, 2, 2, 1]`  
`nums2 = [2, 2]`  
**Output**:  
`[2]`

**Example 2**  
**Input**:  
`nums1 = [4, 9, 5]`  
`nums2 = [9, 4, 9, 8, 4]`  
**Output**:  
`[9, 4]` or `[4, 9]`

---

### 💡 Optimal Approach: Using Hash Sets

- Use two sets to record the unique elements of both arrays.
- Then, iterate through one set and check for existence in the other.
- This guarantees **uniqueness** and avoids duplicates.

---

### ✅ C++ Code

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for (int num : nums2) {
            if (set1.count(num)) {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
