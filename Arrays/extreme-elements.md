## 🧮 Find Largest, Second Largest, Smallest, and Second Smallest in an Array

### 🧾 Problem Statement

Given an array of integers, write a program to find:
- The **largest** element
- The **second largest** element (distinct)
- The **smallest** element
- The **second smallest** element (distinct)

---

### 📌 Example

**Input**:  
`nums = {12, -32, 34, 113, -22, 67, -98, 62, 82, -90}`

**Output**:  

The largest element is: 113  
The second largest element is: 82  
The smallest element is: -98  
The second smallest element is: -90


---

### 💡 Approach

We use a single pass (`O(n)`) through the array and track:
- `largest`, initialized to `INT_MIN`
- `secondLargest`, initialized to `INT_MIN`
- `smallest`, initialized to `INT_MAX`
- `secondSmallest`, initialized to `INT_MAX`

For each element:
- If the number is greater than `largest`, update both `largest` and `secondLargest`.
- If it is smaller than `smallest`, update both `smallest` and `secondSmallest`.
- Make sure to **check for distinctness** before updating second largest or second smallest.

---

### ✅ C++ Code

```cpp
#include <iostream>
using namespace std;
#include <vector>
#include <climits>

int main() {
    vector<int> nums = {12, -32, 34, 113, -22, 67, -98, 62, 82, -90};

    int n = nums.size();
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(nums[i] > largest) {
            secondLargest = largest;
            largest = nums[i];
        }
        else if(nums[i] > secondLargest && nums[i] != largest) {
            secondLargest = nums[i];
        }

        if(nums[i] < smallest) {
            secondSmallest = smallest;
            smallest = nums[i];
        }
        else if(nums[i] < secondSmallest && nums[i] != smallest) {
            secondSmallest = nums[i];
        }
    }

    cout << "The largest element is: " << largest << endl;
    if(secondLargest != INT_MIN) {
        cout << "The second largest element is: " << secondLargest << endl;
    } else {
        cout << "No distinct second largest element." << endl;
    }

    cout << "The smallest element is: " << smallest << endl;
    if(secondSmallest != INT_MAX) {
        cout << "The second smallest element is: " << secondSmallest << endl;
    } else {
        cout << "No distinct second smallest element." << endl;
    }

    return 0;
}
