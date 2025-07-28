# 🚀 LeetCode 8: String to Integer (atoi)

This repository contains a C++ implementation of the `myAtoi` function, which converts a string into a 32-bit signed integer following the rules of the C/C++ `atoi()` function.

---

## 🧩 Problem Statement

Implement the `myAtoi(string s)` function that converts a string to a 32-bit signed integer similar to the C/C++ `atoi` function.

### The function should:
1. Ignore leading whitespace.
2. Handle an optional '+' or '-' sign.
3. Read in digits and convert to integer.
4. Stop at the first non-digit character.
5. Clamp the result to `[-2³¹, 2³¹ − 1]` if it overflows.

---

## 🧪 Example Inputs and Outputs

| Input                | Output         |
|---------------------|----------------|
| `"42"`              | `42`           |
| `"   -42"`          | `-42`          |
| `"4193 with words"` | `4193`         |
| `"words and 987"`   | `0`            |
| `"-91283472332"`    | `-2147483648`  |

---

## 💡 Approach

- Skip leading whitespaces using `isspace()`.
- Check for a sign (`+` or `-`), and record it.
- Traverse the digits using `isdigit()` and form the number.
- Use `long` to track overflow.
- Clamp the value if it exceeds `INT_MAX` or `INT_MIN`.

---

## 🧠 Code

```cpp
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;
        int sign = 1;

        // Skip leading whitespaces
        while (i < n && isspace(s[i])) {
            i++;
        }

        // Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // Parse digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Check overflow
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return (int)(sign * result);
    }
};
