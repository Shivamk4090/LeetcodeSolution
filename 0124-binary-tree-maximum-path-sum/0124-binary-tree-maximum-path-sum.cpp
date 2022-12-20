class Solution {
    int res = -1001;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int left =  max(solve(root->left), 0);
        int right = max(solve(root->right), 0);
        res = max(left+right+root->val, res);
        return max({left, right, 0}) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        solve(root);
        return res;
    }
};