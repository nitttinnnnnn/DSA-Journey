//Leetcode 547 Number of Provinces

// DFS SOLUTION

class Solution {
public:

    void DfsTraversal(int node, vector<vector<int>>& isConnected, vector<int>& visited ,int n){

        visited[node] = 1;
        for(int k=0; k<n; k++){
            if(isConnected[node][k] == 1 && !visited[k]){
                DfsTraversal(k,isConnected,visited,n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<int> visited(n,0);
        int provinces = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                DfsTraversal(i,isConnected,visited,n);
                provinces++;
            }
        }
        return provinces;
    }
};


// BFS SOLUTION


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<int> visited(n,0);
        int provinces = 0;
        queue<int> q;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int j=0; j<n; j++){
                        if(isConnected[node][j] == 1 && !visited[j]){
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
