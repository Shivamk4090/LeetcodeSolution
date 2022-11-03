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
    bool solve(TreeNode* node1, TreeNode* node2){
        if(node1==NULL && node2==NULL) return true;
        if(node1==NULL || node2==NULL || node1->val != node2->val) return false;
        bool ls = solve(node1->left, node2->right);
        bool rs = solve(node1->right,  node2->left);
        return ls && rs;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return solve(root->left, root->right);
    }
};