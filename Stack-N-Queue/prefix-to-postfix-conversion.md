# 🔃 Prefix to Postfix Conversion in C++

This C++ program converts a **prefix expression** into a **postfix expression** using a **stack**. Prefix and postfix notations are common in expression parsing, compiler design, and reverse Polish notation calculators.

---

## 📌 Description

In **prefix notation** (Polish notation), the operator precedes its operands.  
In **postfix notation** (Reverse Polish notation), the operator follows its operands.

This program:
- Scans the prefix expression **from right to left**.
- **Operands** are pushed directly onto the stack.
- On encountering an **operator**, it pops the top two elements from the stack, concatenates them in **postfix form** (`operand1 + operand2 + operator`), and pushes the result back.

---

## ✅ Example

### Input:

Prefix expression: /-AB*+DEF  

### Output:  

Prefix to Postfix conversion: AB-DEF+*/  


---

## 💡 How It Works

Given the prefix: `/ - A B * + D E F`

1. Process `F`, `E`, `D` → Stack: `["F", "E", "D"]`
2. `+` → Pop `D`, `E` → Push `"DE+"`
3. `*` → Pop `"DE+"`, `F` → Push `"DEF+"`
4. `B`, `A` → Push → Stack: `["DEF+", "B", "A"]`
5. `-` → Pop `A`, `B` → Push `"AB-"`
6. `/` → Pop `"AB-"`, `"DEF+"` → Push `"AB-DEF+*/"`

Final result: `"AB-DEF+*/"`

---

## 🧠 Code

```cpp
#include <iostream>
#include <stack>
using namespace std;

string PrefixToPostfixConversion(string str){
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
            // Postfix = operand1 + operand2 + operator
            st.push(top1 + top2 + str[i]);
        }
        i--;
    }
    return st.top();
}

int main(){
    string prefix = "/-AB*+DEF";
    cout << "Prefix expression: " << prefix << endl;
    cout << "Prefix to Postfix conversion: " << PrefixToPostfixConversion(prefix) << endl;
    return 0;
}

