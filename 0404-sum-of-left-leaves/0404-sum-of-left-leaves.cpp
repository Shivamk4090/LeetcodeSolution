/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans =0;
    void solve(TreeNode* node, int x){
        if(node==NULL) return;
        if(node->left==NULL && node->right==NULL && x==0)ans+=node->val;
        solve(node->left, 0);
        solve(node->right, 1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root, 1);
        return ans;
    }
};