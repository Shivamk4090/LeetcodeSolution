class Solution {
    int ans= 0;
    void solve(TreeNode* node, int max){
        if(node==NULL) return;
        
        if(node->val >= max){
            ans++;
            max = node->val; 
        }
        solve(node->left, max);
        solve(node->right, max);
        return ;
    }
public:
    int goodNodes(TreeNode* root) {
        solve(root, INT_MIN);
        return ans;
    }
};