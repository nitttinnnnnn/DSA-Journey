# Leetcode 560: Subarray Sum Equals K

**Difficulty:** Medium  
**Link:** [Leetcode Problem 560](https://leetcode.com/problems/subarray-sum-equals-k/)

---

## 🧩 Problem Statement

Given an array of integers `nums` and an integer `k`, return the total number of **subarrays** whose sum equals `k`.

> A **subarray** is a contiguous non-empty sequence of elements within an array.

---

### 🔢 Examples

**Example 1:**

Input: nums = [1,1,1]  
k = 2  
Output: 2  
Explanation: The subarrays are [1,1] (starting at index 0 and 1)

**Example 2:**

Input: nums = [1,2,3]  
k = 3  
Output: 2  
Explanation: The subarrays are [1,2] and [3]


---

## ✅ Approach: Prefix Sum + HashMap

We use a **hash map** to keep track of how often a prefix sum has occurred.

### 💡 Intuition:
If `prefixSum[j] - prefixSum[i] = k`, then the subarray `nums[i+1..j]` sums to `k`.

---

## 🧠 C++ Code

```cpp
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  // To count subarrays starting from index 0
        int count = 0, sum = 0;

        for (int num : nums) {
            sum += num;

            // If (sum - k) exists in map, add its frequency to count
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            // Add/update current prefix sum count
            prefixSumCount[sum]++;
        }

        return count;
    }
};


