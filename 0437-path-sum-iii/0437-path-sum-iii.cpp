class Solution {
public:
    int ans = 0;
    void sum(TreeNode *root, long long t){
        if(root==NULL) return;
        if(t-root->val==0)ans++;
        sum(root->left, t-root->val);
        sum(root->right, t-root->val);
    }
    void solve(TreeNode* root, int t){
        if(root==NULL) return;
        sum(root, t);
        solve(root->left, t);
        solve(root->right, t);
    }
    int pathSum(TreeNode* root, int t) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        solve(root, t);
        return ans;
    }
};

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