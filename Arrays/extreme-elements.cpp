// This code helps in finding the largest , secondLargest , smallest and secondSmallest element in the given array

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

int main() {
    
    vector<int> nums = {12,-32,34,113,-22,67,-98,62,82,-90};
    
    int n = nums.size();
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;
    
    for(int i=0; i<n; i++){
        if(nums[i] > largest){
            secondLargest = largest;
            largest = nums[i];
        }
        else if(nums[i] > secondLargest && nums[i] != largest){
            secondLargest = nums[i];
        }
         if(nums[i] < smallest){
            secondSmallest = smallest;
            smallest = nums[i];
        }
        else if(nums[i] < secondSmallest && nums[i] != smallest){
            secondSmallest = nums[i];
        }
    }
    
    cout << "The largest element is: " << largest << endl;
    if(secondLargest != INT_MIN){
        cout << "The second largest element is: "<< secondLargest << endl;
    }
    else{
        cout << "No distinct second largest element." << endl;
    }
     
    cout << "The smallest element is: " << smallest << endl;
    if(secondLargest != INT_MAX){
        cout << "The second smallest element is: "<< secondSmallest << endl;
    }
     else{
        cout << "No distinct second second element." << endl;
     }
    
    return 0;
}
    
