## Leetcode 1423: Maximum Points You Can Obtain from Cards

### 🧾 Problem Statement
You have an array `cardPoints` where each element represents the points of a card. You can pick exactly `k` cards from either the **beginning** or the **end** of the array.

Return the **maximum score** you can obtain by picking `k` cards.

---

### 🔍 Example
**Input**:  
`cardPoints = [1,2,3,4,5,6,1]`, `k = 3`

**Output**:  
`12`

**Explanation**:  
You can pick:
- First 2 cards and last 1 card: `1 + 2 + 1 = 4`
- Last 3 cards: `6 + 1 + 5 = 12` ✅ (Best)
- Or other combinations, but maximum is **12**.

---

### 💡 Approach: Sliding Window from Opposite Ends

- Start by picking the **first `k` cards** from the left and calculate their sum (`lsum`).
- Then, **gradually swap** leftmost cards with rightmost cards:
  - Remove one card from the left (`lsum -= cardPoints[i]`)
  - Add one card from the right (`rsum += cardPoints[rightIndex]`)
  - Update `maxSum = max(maxSum, lsum + rsum)`
- Repeat this process `k` times to try every possible left+right split.

---

### ✅ Code (C++)

```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxSum = 0;

        // Step 1: Take the first k cards from the left
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        maxSum = lsum;
        int rightIndex = cardPoints.size() - 1;

        // Step 2: Shift cards from left to right, one by one
        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rightIndex];
            rightIndex--;
            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};
