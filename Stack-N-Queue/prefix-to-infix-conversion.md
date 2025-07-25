# 🔃 Prefix to Infix Conversion in C++

This C++ program converts a **prefix expression** (Polish Notation) into a **fully parenthesized infix expression** using a **stack**. It is helpful in understanding how expressions are evaluated in compilers and interpreters.

---

## 📌 Description

In **prefix notation**, the operator comes **before** the operands (e.g., `+AB`), while in **infix notation**, the operator is placed **between** operands (e.g., `A+B`).  
This program uses a stack to convert from prefix to infix:

- The expression is **scanned from right to left**.
- **Operands** are pushed onto the stack.
- **Operators** pop the top two operands, combine them with the operator in infix format, and push the resulting string back.

---

## ✅ Example

### Input:

Prefix expression: *+PQ-MN  


### Output:

Prefix to Infix conversion: ((P+Q)*(M-N))  


---

## 💡 How It Works

Given a prefix expression `*+PQ-MN`, the evaluation proceeds like this:

1. Process `N`, `M` → Stack: `["N", "M"]`
2. Encounter `-` → Pop `"M"` and `"N"`, push `"(M-N)"`
3. Process `Q`, `P` → Stack: `["(M-N)", "Q", "P"]`
4. Encounter `+` → Pop `"P"` and `"Q"`, push `"(P+Q)"`
5. Encounter `*` → Pop `"(P+Q)"` and `"(M-N)"`, push `((P+Q)*(M-N))`

---

## 🧠 Code

```cpp
#include <iostream>
#include <stack>
using namespace std;

string PrefixToInfixConversion(string str){
    int n = str.size();
    int i = n - 1;
    stack<string> st;

    while(i >= 0){
        if((str[i] >= 'A' && str[i] <= 'Z') || 
           (str[i] >= 'a' && str[i] <= 'z') ||
           (str[i] >= '0' && str[i] <= '9')) {
            // Convert char to string before pushing
            string operand(1, str[i]);
            st.push(operand);
        }
        else {
            string top1 = st.top(); st.pop();
            string top2 = st.top(); st.pop();
            string newString = '(' + top1 + str[i] + top2 + ')';
            st.push(newString);
        }
        i--;
    }
    return st.top();
}

int main(){
    string prefix = "*+PQ-MN";
    cout << "Prefix expression: " << prefix << endl;
    cout << "Prefix to Infix conversion: " << PrefixToInfixConversion(prefix) << endl;
    return 0;
}
