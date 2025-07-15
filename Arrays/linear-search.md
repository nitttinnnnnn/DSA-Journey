## 🔍 Linear Search in an Array

### 🧾 Problem Statement

Given an array of integers and a target element, write a program to search for the target in the array using **linear search**.  
If the element is found, return its index; otherwise, indicate that it is not found.

---

### 📌 Example

**Input**  

nums = {1, 2, 3, 4, 5}  
target = 3  

Output:  

Found at index: 2

---

### 💡 Approach: Simple Linear Scan

- Start from the beginning of the array.
- Compare each element to the target.
- If found, print its index and exit.
- If the loop ends without finding it, print "Not found".

`This approach works well for small or unsorted arrays where quick lookup structures aren't available.`

---

### ✅ C++ Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

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
