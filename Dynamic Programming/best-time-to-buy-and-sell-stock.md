## Leetcode 121: Best Time to Buy and Sell Stock

### 🧾 Problem Statement
You are given an array `prices` where `prices[i]` is the price of a stock on the `i-th` day.  
You want to maximize your profit by choosing a **single day to buy** one stock and choosing a **different day in the future to sell** that stock.

Return the **maximum profit** you can achieve.  
If no profit can be made, return `0`.

---

### 🔍 Example

**Input**:  
`prices = [7,1,5,3,6,4]`  
**Output**: `5`  
**Explanation**: Buy on day 2 (price = 1), sell on day 5 (price = 6), profit = 6 - 1 = 5.

---

### 💡 Approach: Greedy with State Tracking (DP Optimization)

- Initialize `mini` as the minimum price seen so far (`prices[0]`)
- Track the maximum profit using:
  ```cpp
  profit = max(profit, prices[i] - mini)
