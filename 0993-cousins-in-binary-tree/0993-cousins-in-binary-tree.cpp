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
    int xp=-1, xl=-1, yp=-1, yl=-2;
    void solve(TreeNode* node, int x, int y, int p, int l){
        if(node==NULL) return;
        if(node->val==x){
            xp = p;
            xl = l;
        }else if(node->val==y){
            yp = p;
            yl = l;
        }
        solve(node->left, x, y, node->val, l+1);
        solve(node->right, x, y, node->val, l+1);
        
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        solve(root, x, y,root->val, 0);
        if(xp!=yp && xl==yl) return true;
        return false;
    }
};