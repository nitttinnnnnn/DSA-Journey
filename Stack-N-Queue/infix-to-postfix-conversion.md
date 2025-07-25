# 🧮 Infix to Postfix Conversion in C++

This project implements a C++ program that converts an infix expression (like `a+b*(c^d-e)`) into its corresponding postfix expression (`abcd^e-*+`) using a stack-based algorithm.

---

## 📌 Features

- ✅ Handles operands (`a-z`, `A-Z`, `0-9`)
- ✅ Supports operators: `+`, `-`, `*`, `/`, `^`
- ✅ Handles parentheses `(` and `)`
- ✅ Maintains operator precedence
- ✅ Stack-based conversion

---

## 🛠️ How It Works

### Operator Precedence Table

| Operator | Precedence | Associativity |
|----------|------------|---------------|
| `^`      | 3          | Right         |
| `*`, `/` | 2          | Left          |
| `+`, `-` | 1          | Left          |

### Algorithm Logic

1. **Operands**: Directly add to output.
2. **Left Parenthesis** `(`: Push to stack.
3. **Right Parenthesis** `)`:
   - Pop from stack to output until `(` is found.
4. **Operator**:
   - Pop higher or equal precedence operators from stack.
   - Push the current operator to stack.
5. **End of Expression**:
   - Pop all remaining operators from the stack to output.

---



## 💻 Code Example

```cpp
#include <iostream>
#include <stack>
using namespace std;

int priority(char op){
    if(op == '^') return 3;
    else if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    else return 0;
}

string InfixToPostFixConversion(string str){
    int i = 0;
    int n = str.size();
    stack<char> st;
    string answer = "";
    while(i < n){
        if((str[i] >= 'A' && str[i] <= 'Z') || 
           (str[i] >= 'a' && str[i] <= 'z') ||
           (str[i] >= '0' && str[i] <= '9')){
            answer += str[i];
        }
        else if(str[i] == '('){
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            while(!st.empty() && st.top() != '('){
                answer += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        else{
            while(!st.empty() && priority(str[i]) <= priority(st.top())){
                answer += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        i++;
    }
    while(!st.empty()){
        answer += st.top();
        st.pop();
    }
    return answer;
}

int main(){
    string infix = "a+b*(c^d-e)";
    cout << "Infix expression: " << infix << endl;
    cout << "Infix to postfix conversion: " << InfixToPostFixConversion(infix) << endl;
    return 0;
}
```

## 🧪 Example Output  

Infix expression: a+b*(c^d-e)  
Infix to postfix conversion: abcd^e-*+  
