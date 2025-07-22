#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


string convertDecimalToBinary(int decimalNum){
    string result = "";
    while(decimalNum != 0){
        if(decimalNum % 2 == 0){
            result += "0";
        }
        else{
            result += "1";
        }
        decimalNum /= 2;
    }
    reverse(result.begin(),result.end());
    return result;
}

int convertBinaryToDecimal(string binaryNum){
    int num = 0;
    int len = binaryNum.size();
    int powerOf2 = 1;
    reverse(binaryNum.begin() , binaryNum.end());
    for(int i=0; i<len; i++){
        if(binaryNum[i]=='1'){
            num = num + powerOf2;
        }
        powerOf2 *= 2;
    }
    
    return num;
}


int main(){
    cout << convertDecimalToBinary(13) << endl;
    cout << convertBinaryToDecimal("11011");
    return 0;
}









