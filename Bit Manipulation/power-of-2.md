# 🔢 Power of Two - C++ Bit Manipulation

This repository contains a simple and efficient C++ solution to check whether a given integer is a power of two using bitwise operations.

---

## 📘 Problem Statement

Determine whether a given integer `n` is a power of two.

### ✅ Constraints
- An integer `n` is a power of two **if there exists an integer x such that** `n == 2^x`.
- `n` must be a **positive number**.

---

## 💡 Approach

This solution uses **bit manipulation** to check if a number is a power of two. A number that is a power of two has exactly **one bit set** in its binary representation.

For example:
- `1` -> `0001`
- `2` -> `0010`
- `4` -> `0100`
- `8` -> `1000`

Subtracting `1` from any of these numbers flips all the bits **after and including** the only set bit:

n = 8 (1000)  
n - 1 = 7 (0111)  
n & (n - 1) = 0 ✅  


If `n & (n - 1)` results in 0, it is a power of two.

---

## 🧠 Algorithm

1. Return `false` if `n` is less than or equal to 0.
2. Use the expression `(n & (n - 1)) == 0` to check if it's a power of two.
3. Return `true` if the condition holds.

---

## 🚀 C++ Code

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};
