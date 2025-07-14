## Leetcode 2149: Rearrange Array Elements by Sign

### 🧾 Problem Statement
You are given a **0-indexed integer array `nums`** of **even length** consisting of an equal number of **positive and negative integers**.

You should **rearrange** the elements of `nums` such that:
- Every **positive** number is followed by a **negative**, and so on.
- The relative order of **positive and negative numbers** is preserved.

Return the resulting array.

---

### 🔍 Example

**Input**:  
`nums = [3,1,-2,-5,2,-4]`

**Output**:  
`[3,-2,1,-5,2,-4]`

**Explanation**:
- Positives: [3, 1, 2]
- Negatives: [-2, -5, -4]
- Alternating result: [3, -2, 1, -5, 2, -4]

---

### 💡 Approach: Two-Pointer Placement (Greedy)

- Initialize two pointers:
  - `positive = 0` (even index positions)
  - `negative = 1` (odd index positions)
- Traverse through the input array:
  - If the number is positive, place it at the `positive` index and increment `positive += 2`
  - If the number is negative, place it at the `negative` index and increment `negative += 2`
- Return the final rearranged array.

---

### ✅ Code (C++)

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positive = 0;
        int negative = 1;
        int n = nums.size();
        vector<int> answer(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                answer[positive] = nums[i];
                positive += 2;
            } else {
                answer[negative] = nums[i];
                negative += 2;
            }
        }

        return answer;
    }
};
