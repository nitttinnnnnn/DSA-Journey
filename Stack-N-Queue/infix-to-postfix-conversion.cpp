#include <iostream>
#include <stack>
using namespace std;

int priority(char op){
    if(op == '^'){
        return 3;
    }
    else if(op == '*' || op == '/'){
        return 2;
    }
    else if(op == '+' || op == '-'){
        return 1;
    }
    else{
        return 0;
    }
    
}

string InfixToPostFixConversion(string str){
    int i = 0;
    int n = str.size();
    stack<char> st;
    string answer = "";
    while(i < n){
        if(str[i] >= 'A' && str[i] <= 'Z' || 
           str[i] >= 'a' && str[i] <= 'z' ||
           str[i] >= '0' && str[i] <= '9'
        ){
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
            while(!st.empty() && priority(str[i]) <= priority(st.top())){
                answer = answer + st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        i++;
    }
    while(!st.empty()){
        answer = answer + st.top();
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
