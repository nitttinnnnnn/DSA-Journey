# 🔁 Decimal to Binary and Binary to Decimal Converter in C++

This C++ program provides two functions to convert:

- Decimal to Binary (`convertDecimalToBinary`)
- Binary to Decimal (`convertBinaryToDecimal`)

---

## 📌 Features

- Converts any positive decimal number to binary.
- Converts valid binary strings to decimal.
- Uses basic string and math operations (no bitwise).

---

## 🧠 Code Explanation

### 1. `convertDecimalToBinary(int decimalNum)`

- Takes a base-10 integer as input.
- Uses modulus (`% 2`) to extract binary digits.
- Reverses the collected digits to get the correct binary representation.

**Example:**

Input: 13  
Process: 13 % 2 = 1, 6 % 2 = 0, 3 % 2 = 1, 1 % 2 = 1  
Binary (after reverse): 1101  


### 2. `convertBinaryToDecimal(string binaryNum)`

- Takes a binary string like `"11011"` as input.
- Reverses the string to process from least to most significant bit.
- Uses powers of 2 to compute the decimal value.

**Example:**

Input: "11011"  
Reversed: "11011"  
Calculation: 1×1 + 1×2 + 0×4 + 1×8 + 1×16 = 27  
Output: 27  


---

## 🧪 Sample Code

```cpp
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Decimal to Binary
string convertDecimalToBinary(int decimalNum) {
    string result = "";
    while (decimalNum != 0) {
        if (decimalNum % 2 == 0) {
            result += "0";
        } else {
            result += "1";
        }
        decimalNum /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Binary to Decimal
int convertBinaryToDecimal(string binaryNum) {
    int num = 0;
    int len = binaryNum.size();
    int powerOf2 = 1;
    reverse(binaryNum.begin(), binaryNum.end());

    for (int i = 0; i < len; i++) {
        if (binaryNum[i] == '1') {
            num = num + powerOf2;
        }
        powerOf2 *= 2;
    }

    return num;
}

int main() {
    cout << convertDecimalToBinary(13) << endl;      // Output: 1101
    cout << convertBinaryToDecimal("11011") << endl; // Output: 27
    return 0;
}
