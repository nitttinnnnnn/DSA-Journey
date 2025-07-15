## Leetcode 1358: Number of Substrings Containing All Three Characters

### 🧾 Problem Statement

Given a string `s` consisting only of characters `'a'`, `'b'`, and `'c'`, return the number of substrings containing **at least one occurrence of each** of these characters.

---

### 🔍 Example

**Input**:  
`s = "abcabc"`

**Output**:  
`10`

**Explanation**:  
There are 10 substrings that contain at least one `'a'`, `'b'`, and `'c'`:
- `"abc"`, `"abca"`, `"abcab"`, `"abcabc"`, `"bca"`, `"bcab"`, `"bcabc"`, `"cab"`, `"cabc"`, `"abc"`

---

### 💡 Optimal Approach: Sliding Window with Two Pointers

We maintain a sliding window with two pointers `l` and `r` such that the substring `s[l..r]` contains at least one `'a'`, one `'b'`, and one `'c'`.

**Key Idea**:  
Once we find such a window ending at `r`, all substrings starting from `l`, `l+1`, ..., up to the end of the string are valid.

---

### ✅ C++ Code

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int hash[3] = {0}; // count of 'a', 'b', 'c'
        int l = 0;
        int count = 0;

        for (int r = 0; r < n; r++) {
            hash[s[r] - 'a']++;

            // shrink window while all 3 characters are present
            while (hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
                count += (n - r);        // all substrings from [l..r] to [l..n-1] are valid
                hash[s[l] - 'a']--;      // shrink the window
                l++;
            }
        }

        return count;
    }
};
