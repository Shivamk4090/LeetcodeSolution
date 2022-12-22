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
    int ans = 1e6;
    void dfs(TreeNode* root, int d){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            ans = min(ans, d);
        }
        dfs(root->left, d+1);
        dfs(root->right, d+1);

    }
public:
    int minDepth(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(root==NULL) return 0;
        dfs(root, 1);
        return ans;
    }
};