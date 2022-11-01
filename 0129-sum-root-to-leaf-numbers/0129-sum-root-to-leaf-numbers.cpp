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
    int ans = 0;
    void solve(TreeNode* root, string s){
        
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            int temp = stoi(s + to_string(root->val));
            ans += temp;    
        }
        solve(root->left, s +  to_string(root->val));
        solve(root->right, s + to_string(root->val));
        
    }
    int sumNumbers(TreeNode* root) {
        solve(root, "");
        return ans;
    }
};