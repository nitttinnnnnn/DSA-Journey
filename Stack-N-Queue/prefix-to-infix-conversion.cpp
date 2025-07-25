#include <iostream>
#include <stack>
using namespace std;


string PrefixToInfixConversion(string str){
    
    int n = str.size();
    int i = n-1;
    stack<string> st;
    
    while(i >= 0){
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
