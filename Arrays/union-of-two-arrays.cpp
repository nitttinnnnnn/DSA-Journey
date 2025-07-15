// Union of two arrays

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums1 = {1,1,2,3,4,5};
    vector<int> nums2 = {2,3,4,4,5,6,3};
    vector<int> Union;
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int j = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
     while(i < n1 && j < n2){
        if(nums1[i] < nums2[j]){
            if(Union.size() == 0 || Union.back() != nums1[i]){
                Union.push_back(nums1[i]);
            }
            i++;
        }
        else if(nums1[i] > nums2[j]){
            if(Union.size() == 0 || Union.back() != nums2[j]){
                Union.push_back(nums2[j]);
            }
            j++;
        }
        else{
            if(Union.size() == 0 || Union.back() != nums1[i]){
                Union.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }
     while(j<n2){
        if(Union.size()==0 || Union.back()!=nums2[j]){
            Union.push_back(nums2[j]);
        }
        j++;
    }
    while(i<n1){
        if(Union.size()==0 || Union.back()!=nums1[i]){
            Union.push_back(nums1[i]);
        }
        i++;
    }
    
    for(int num : Union){
        cout << num << " ";
    }
}












