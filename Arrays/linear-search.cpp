// Linear search

#include <iostream>
using namespace std;
#include <vector>

int main() {
    
    vector<int> nums = {1,2,3,4,5};
    int size = nums.size();
    int target = 3;
    
    for(int i=0; i<size; i++){
        if(nums[i]==target){
            cout << "Found at index: " << i << endl;
            return 0;
        }
    }
    cout << "Not found";
    return 0;
}
