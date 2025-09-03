struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    void traversal(TreeNode* root, vector<int>& answer){
        if(root == NULL) return;
        answer.push_back(root -> val);
        traversal(root -> left , answer);
        traversal(root -> right , answer);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        traversal(root , answer);
        return answer;
    }
};
