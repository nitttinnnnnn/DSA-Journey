# 🔁 Infix to Prefix Conversion in C++

This project implements a **C++ program** that converts a given **infix expression** (e.g., `(A+B)*C-D+E`) to its corresponding **prefix notation** (e.g., `++-*+ABCDE`) using a stack-based approach.

---

## 📌 Features

- ✅ Supports operands (`A-Z`, `a-z`, `0-9`)
- ✅ Handles standard arithmetic operators: `+`, `-`, `*`, `/`, `^`
- ✅ Preserves operator precedence and associativity
- ✅ Properly processes parentheses
- ✅ Uses `stack` and `reverse` logic to convert infix to prefix

---

## 🛠️ Algorithm Overview

### 🔄 Conversion Strategy

To convert an **infix expression** to **prefix**, the following steps are followed:

1. **Reverse** the input infix string.
2. **Swap** each `(` with `)` and vice versa.
3. Convert the modified expression to **postfix** using a stack.
4. **Reverse** the result to get the final **prefix** expression.

---

## 🧮 Operator Precedence Table

| Operator | Precedence | Associativity |
|----------|------------|---------------|
| `^`      | 3          | Right         |
| `*`, `/` | 2          | Left          |
| `+`, `-` | 1          | Left          |

---

## 💻 Code

```cpp
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int priority(char op){
    if(op == '^') return 3;
    else if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    else return 0;
}

string InfixToPreFixConversion(string str){
    reverse(str.begin(), str.end());

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(') str[i] = ')';
        else if(str[i] == ')') str[i] = '(';
    }

    int i = 0;
    int n = str.size();
    stack<char> st;
    string answer = "";

    while(i < n){
        if((str[i] >= 'A' && str[i] <= 'Z') || 
           (str[i] >= 'a' && str[i] <= 'z') ||
           (str[i] >= '0' && str[i] <= '9')){
            answer = answer + str[i];
        }
        else if(str[i] == '('){
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            while(!st.empty() && st.top() != '('){
                answer = answer + st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(str[i] == '^'){
                while(!st.empty() && priority(str[i]) <= priority(st.top())){
                    answer = answer + st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(str[i]) < priority(st.top())){
                    answer = answer + st.top();
                    st.pop();
                }
            }
            st.push(str[i]);
        }
        i++;
    }

    while(!st.empty()){
        answer = answer + st.top();
        st.pop();
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

int main(){
    string infix = "(A+B)*C-D+E";
    cout << "Infix expression: " << infix << endl;
    cout << "Infix to prefix conversion: " << InfixToPreFixConversion(infix) << endl;
    return 0;
}

```

---

## 🧪 Sample Output  

Infix expression: (A+B)*C-D+E  
Infix to prefix conversion: ++-*+ABCDE  

