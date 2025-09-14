# LeetCode 547 - Number of Provinces

## Problem Statement
We are given an `n x n` adjacency matrix `isConnected` where:

- `isConnected[i][j] = 1` → city `i` and city `j` are directly connected.  
- `isConnected[i][j] = 0` → city `i` and city `j` are **not** directly connected.  

A **province** is defined as a group of **directly or indirectly connected cities**, with no connections outside the group.  

We need to **return the total number of provinces**.

---

## Example
### Input:

isConnected = [[1,1,0],
[1,1,0],
[0,0,1]]


### Output:

2


**Explanation:**  
- City `0` and city `1` form one province.  
- City `2` is isolated, so it forms another province.  

---

## Approach 1: Depth-First Search (DFS)

We treat the adjacency matrix as a graph:
1. Maintain a `visited` array to mark cities we’ve already seen.  
2. For each unvisited city, run DFS to visit all cities in the same province.  
3. Count how many times we start a new DFS → this gives the number of provinces.

### DFS Code:
```cpp

class Solution {
public:
    void DfsTraversal(int node, vector<vector<int>>& isConnected, vector<int>& visited ,int n) {
        visited[node] = 1;
        for(int k = 0; k < n; k++) {
            if(isConnected[node][k] == 1 && !visited[k]) {
                DfsTraversal(k, isConnected, visited, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                DfsTraversal(i, isConnected, visited, n);
                provinces++;
            }
        }
        return provinces;
    }
};


```
---

## Approach 2: Breadth-First Search (BFS)

Instead of recursion, we can use a queue to perform BFS:
1. For each unvisited city, push it into a queue.
2. Pop cities one by one, and push all their directly connected (unvisited) neighbors into the queue.
3. After BFS completes, we’ve found one province.

### BFS Code:

```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;
        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = 1;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for(int j = 0; j < n; j++) {
                        if(isConnected[node][j] == 1 && !visited[j]) {
                            q.push(j);
                            visited[j] = 1;
                        }
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }
};

