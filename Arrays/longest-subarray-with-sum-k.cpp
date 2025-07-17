// Longest subarray with sum k
// This code is the optimal solution if you're presented with an array that consists of positives , negatives and zero

#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map <int,int> mpp;
    int nums[10] = {1,2,3,1,1,1,1,0,0,5};
    int sum = 0;
    int maxLen = 0;
    int k = 3;
    for(int i=0; i<10; i++){
        sum += nums[i];
        if(sum == k){
            maxLen = max(maxLen,i+1);
        }
        int rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            int len = i - mpp[rem];
            maxLen = max(maxLen , len);
        }
        if(mpp.find(sum) == mpp.end()){
            mpp[sum] = i;
        }
    }
    cout << "Maximum possible subarray: " << maxLen;
    
    return 0;
}
