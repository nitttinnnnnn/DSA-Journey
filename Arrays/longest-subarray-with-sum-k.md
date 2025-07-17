# 🚀 Maximum Length Subarray with Given Sum (C++)

This repository contains a C++ program that calculates the **maximum length of a subarray** from a given array whose **sum equals a specific value `k`**.

---

## 📌 Problem Statement

Given an array of integers and an integer `k`, find the **maximum length of a subarray** that sums to `k`.

---

## 🛠️ Algorithm Used

- Prefix Sum
- `unordered_map` for storing the first occurrence of each prefix sum
- Time Complexity: **O(n)**
- Space Complexity: **O(n)**

---

## 💡 Logic Explanation

1. **Prefix sum (`sum`)** keeps track of the total sum up to the current index.
2. If `sum == k`, it means the subarray from index `0` to `i` has the desired sum.
3. If `(sum - k)` is found in the map, then a subarray ending at `i` has the desired sum.
4. We store the **first occurrence** of each `sum` in the map to maximize the length.

---

## 📎 Sample Input

```cpp
int nums[10] = {1, 2, 3, 1, 1, 1, 1, 0, 0, 5};
int k = 3;
```

## Output

```cpp
Maximum possible subarray: 6
```

## CODE
```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> mpp;
    int nums[10] = {1, 2, 3, 1, 1, 1, 1, 0, 0, 5};
    int sum = 0;
    int maxLen = 0;
    int k = 3;

    for (int i = 0; i < 10; i++) {
        sum += nums[i];

        // Case 1: Whole subarray from 0 to i sums to k
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // Case 2: If (sum - k) is seen before
        int rem = sum - k;
        if (mpp.find(rem) != mpp.end()) {
            int len = i - mpp[rem];
            maxLen = max(maxLen, len);
        }

        // Store the first occurrence of the current sum
        if (mpp.find(sum) == mpp.end()) {
            mpp[sum] = i;
        }
    }

    cout << "Maximum possible subarray: " << maxLen;
    return 0;
}


