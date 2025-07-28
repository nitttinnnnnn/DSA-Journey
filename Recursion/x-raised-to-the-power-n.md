# 🚀 LeetCode 50: Pow(x, n)

This repository contains an optimized C++ implementation of the `myPow` function, which calculates `x^n` (x raised to the power n) efficiently using **Exponentiation by Squaring**.

---

## 🧩 Problem Statement

Implement `myPow(double x, int n)` that calculates `x` raised to the power `n` (`xⁿ`), where `n` is an integer.

---

## ✅ Requirements

- Avoid using built-in library functions like `pow()`.
- Handle **negative exponents** correctly.
- Ensure **time efficiency**, especially for large `n`.

---

## 🧠 Algorithm Used: Exponentiation by Squaring

### Why?

This method reduces the time complexity from **O(n)** to **O(log n)** by squaring the base and halving the exponent.

---

## 🧾 Code

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;      // Use long long to safely handle INT_MIN
        double answer = 1;

        if (power < 0) {
            power = -power;       // Make power positive for calculation
        }

        while (power > 0) {
            if (power % 2 != 0) { // If power is odd
                answer = answer * x;
                power--;
            } else {              // If power is even
                x = x * x;
                power = power / 2;
            }
        }

        if (n < 0) {
            answer = 1 / answer;  // Handle negative exponent
        }

        return answer;
    }
};

```
  

## 🕐 Time and Space Complexity  

Time Complexity	  O(log n)  
Space Complexity	O(1)  

## 📌 Notes
long long is used to avoid overflow when n = INT_MIN (as -INT_MIN is undefined in int)  

The method is iterative, not recursive (saves stack space)  

Efficient for very large positive or negative exponents  
