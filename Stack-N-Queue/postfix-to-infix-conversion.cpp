#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


string PostfixToInfixConversion(string str){
    
    int i = 0;
    int n = str.size();
    stack<string> st;
    
    while(i < n){
        if(str[i] >= 'A' && str[i] <= 'Z' || 
           str[i] >= 'a' && str[i] <= 'z' ||
           str[i] >= '0' && str[i] <= '9'
        ){
            // Convert char to string before pushing
            string operand(1, str[i]);
            st.push(operand);
        }
        else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
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
