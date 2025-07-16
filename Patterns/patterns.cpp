#include <iostream>
using namespace std;

void pattern1(int n , int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern2(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern3(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern4(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << i+1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern5(int n){
    for(int i=n; i>0; i--){
        for(int j=0; j<i; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern6(int n){
    for(int i=n; i>0; i--){
        for(int j=0; j<i; j++){
            cout << j+1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    
    pattern1(3,5);
    pattern2(5);
    pattern3(5);
    pattern4(5);
    pattern5(5);
    pattern6(5);
    return 0;
}

