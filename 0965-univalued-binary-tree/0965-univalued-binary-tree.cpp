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
    bool solve(TreeNode* root, int x){
        if(root == NULL) return true;
        if(root->val !=x ) return false;
        bool ans1 = solve(root->left, x);
        bool ans2 = solve(root->right, x);
        if(ans1==false || ans2==false)return false;
        return true;
    }
    
    bool isUnivalTree(TreeNode* root) {
        return solve(root, root->val);    
    }
};