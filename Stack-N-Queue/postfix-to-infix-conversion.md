# 🧮 Postfix to Infix Conversion in C++

This program converts a **postfix expression** (Reverse Polish Notation) into an **infix expression** using a stack. It demonstrates a classical **stack-based algorithm** used in expression parsing.

---

## 📌 Description

Given a postfix expression (e.g., `AB+`), the program converts it to its equivalent infix form (e.g., `(A+B)`).

The code uses the C++ Standard Template Library (`<stack>`) to process each character in the postfix string:

- **Operands** are pushed to a stack.
- **Operators** pop two operands from the stack, combine them with the operator in between, wrap the result in parentheses, and push it back.

---

## ✅ Example

### Input:

Postfix expression: AB-DE+F*/  

---

### Output:

Postfix to Infix conversion: (((A-B)*(D+E))/F)  


---

## 📦 Code

```cpp
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string PostfixToInfixConversion(string str){
    int i = 0;
    int n = str.size();
    stack<string> st;
    
    while(i < n){
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
            string newString = '(' + top2 + str[i] + top1 + ')';
            st.push(newString);
        }
        i++;
    }
    return st.top();
}

int main(){
    string postfix = "AB-DE+F*/";
    cout << "Postfix expression: " << postfix << endl;
    cout << "Postfix to Infix conversion: " << PostfixToInfixConversion(postfix) << endl;
    return 0;
}
