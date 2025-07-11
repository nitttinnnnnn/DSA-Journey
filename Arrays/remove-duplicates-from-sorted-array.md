## Leetcode 26: Remove Duplicates from Sorted Array

### Problem:
Given a sorted array `nums`, remove the duplicates **in-place** such that each unique element appears only once.  
Return the new length `k` such that the first `k` elements are the unique values.

> ⚠️ You must not use extra space for another array.  
> Do the operation in-place with O(1) extra memory.

---

### 💡 Approach: Two Pointer Technique

- Use two pointers `l` and `r`:
  - `l` keeps track of the **last unique index**
  - `r` scans the array for a new unique value
- If `nums[r] != nums[l]`, it means we found a new unique element.
  - Move `l` forward
  - Copy `nums[r]` to `nums[l]`
- Continue until the end of the array.

---
