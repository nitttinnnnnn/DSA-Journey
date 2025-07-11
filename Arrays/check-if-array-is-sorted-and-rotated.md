## 🔁 Leetcode 1752: Check if the Array is Sorted and Rotated

### 📘 Problem:
Given a circularly rotated array `nums`, check if it was originally sorted in non-decreasing order and rotated **some number of times** (possibly 0).

> Return `true` if the array is sorted and rotated.  
> Otherwise, return `false`.

---

### 💡 Approach: Circular Comparison with Modulo

- We simulate checking the array as if it were circular by using the modulo operator `%`.
- We compare each pair of consecutive elements in this "virtual" circular array:
  - If `nums[(i-1)%n] <= nums[i%n]`, it's a valid part of a non-decreasing sequence.
  - Keep counting how many valid pairs we have.
- If we find `n - 1` such valid consecutive pairs, that means the array is sorted and rotated → return `true`.
- If the array size is 1 → return `true` directly (a single element is always sorted).

---
