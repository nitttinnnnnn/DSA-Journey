# 🔁 Postfix to Prefix Conversion in C++

This C++ program converts a **postfix expression** (Reverse Polish Notation) into a **prefix expression** (Polish Notation) using a **stack**. It is useful in compiler design and expression evaluation where operator precedence is critical.

---

## 📌 Description

In postfix notation, the operator comes **after** the operands (e.g., `AB+`), whereas in prefix notation, the operator comes **before** the operands (e.g., `+AB`).

This program uses the stack data structure to achieve the conversion:

- **Operands** are pushed onto the stack.
- **Operators** pop the top two operands from the stack, prepend the operator, and push the resulting string back.

---

## ✅ Example

### Input:

Postfix expression: AB-DE+F*/  


### Output:

Postfix to Prefix conversion: /*-AB+DEF  


---

## 💡 How It Works

Given an operator `op` and two operands `A` and `B` (already in prefix form):

Postfix: A B op  
Prefix: op A B  


This logic is applied iteratively using a stack.

---

## 🧠 Code

```cpp
#include <iostream>
#include <stack>
using namespace std;

string PostfixToPrefixConversion(string str){
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
            st.push(str[i] + top2 + top1);
        }
        i++;
    }
    return st.top();
}

int main(){
    string postfix = "AB-DE+F*/";
    cout << "Postfix expression: " << postfix << endl;
    cout << "Postfix to Prefix conversion: " << PostfixToPrefixConversion(postfix) << endl;
    return 0;
}
