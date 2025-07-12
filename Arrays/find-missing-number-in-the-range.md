## Leetcode 268: Missing Number

### Problem:
Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the **only number** in the range that is **missing** from the array.

> The array contains `n` numbers, but one number in the range `[0, n]` is missing.  
> Return that missing number.

---

### Approach: Sum Formula

- The sum of first `n` natural numbers is:  
  \[
  total = n(n+1)/2
  \]
- We compute the **actual sum** of the array elements.
- The missing number is simply:
  \[
  \{missing} = \{total} - \{sum}
  \]

---

### Code Logic:
```cpp
int n = nums.size();
int total = n * (n + 1) / 2;  // Expected sum of numbers from 0 to n
int sum = 0;

for (int i = 0; i < n; i++) {
    sum += nums[i];  // Actual sum
}

return total - sum;  // The missing number
