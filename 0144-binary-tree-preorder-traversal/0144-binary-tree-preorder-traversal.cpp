class Solution {
    vector<int> ans;
    void solve(TreeNode* root){
        if (root==NULL) return;
        ans.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        solve(root);
        return ans;
    }
};