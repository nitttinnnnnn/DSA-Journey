# 🔗 Union of Two Arrays (C++)

This C++ program finds the **union** of two integer arrays, ensuring that the result contains **unique elements only**, and prints the sorted union.

---

## 📌 Problem Statement

Given two integer arrays `nums1` and `nums2`, the task is to find their **union**, i.e., all distinct elements present in either `nums1`, `nums2`, or both.

---

## ✅ Features

- Accepts two predefined vectors: `nums1` and `nums2`.
- Sorts both arrays.
- Uses two-pointer technique to efficiently compute the union.
- Avoids duplicate elements in the result.
- Outputs the union elements in sorted order.

---

## 📦 Sample Input

```cpp
vector<int> nums1 = {1, 1, 2, 3, 4, 5};
vector<int> nums2 = {2, 3, 4, 4, 5, 6, 3};
```

## Output

1 2 3 4 5 6

---

## 🧠 How It Works

**Sorting:**
- The vectors nums1 and nums2 are sorted to prepare for two-pointer traversal.

**Two-Pointer Technique:**
- Traverse both arrays simultaneously.
- Compare elements at current indices i and j.
- Add the smaller one to the union if it's not already added.
- If both are equal, add one and advance both pointers.
  

**Post-Traversal Cleanup:**
- Add any remaining elements from either array, again skipping duplicates.

