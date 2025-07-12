## 🎨 Leetcode 75: Sort Colors

### 📘 Problem:
Given an array `nums` with `n` objects colored red (`0`), white (`1`), or blue (`2`), **sort them in-place** so that objects of the same color are adjacent and in the order red, white, and blue.

> You must solve this problem without using any built-in sort function.

---

### 💡 Approach: Dutch National Flag Algorithm

- Use **three pointers**:
  - `low` for the boundary of 0s (red)
  - `mid` to traverse the array
  - `high` for the boundary of 2s (blue)

- Traverse the array once:
  - If `nums[mid] == 0`: swap with `low`, then increment both `low` and `mid`
  - If `nums[mid] == 1`: just move `mid` forward
  - If `nums[mid] == 2`: swap with `high`, then decrement `high`

- This ensures:
  - All 0s are moved to the beginning
  - All 2s are moved to the end
  - All 1s stay in the middle

---

### ✅ Code:
```cpp
// Leetcode 75 : Sort Colors
// Solution follows the Dutch National Flag algorithm

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
