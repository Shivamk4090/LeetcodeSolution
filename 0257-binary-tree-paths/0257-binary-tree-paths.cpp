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
    vector<string> v;
    void solve(TreeNode* root, string s){
        if(root==NULL) return;
        
        string x;
        if(s.size()>0) x = s + "->" +to_string(root->val);
        else x = s + to_string(root->val);
        
        if(root->left==NULL && root->right==NULL)
            v.push_back(x);

        solve(root->left, x);
        solve(root->right, x);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");
        return v;        
    }
};