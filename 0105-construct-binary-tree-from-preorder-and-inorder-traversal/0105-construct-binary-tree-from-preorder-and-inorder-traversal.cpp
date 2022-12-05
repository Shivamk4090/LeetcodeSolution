class Solution {
    TreeNode* solve(vector<int>preorder, vector<int>inorder){
        vector<int> inleft, preleft, inright, preright;
        if(preorder.size()==0) return NULL;

        // root
        TreeNode* root = new TreeNode(preorder[0]);
        
        int inLeftEnd = -1;
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i]==preorder[0]){
               inLeftEnd = i-1; 
                break;
            }
        }
        for(int i=0; i<=inLeftEnd; i++){
            inleft.push_back(inorder[i]);
        }
        for(int i=inLeftEnd+2; i<inorder.size(); i++){
            inright.push_back(inorder[i]);
        }
        int size = inleft.size();
        
        for(int i=1; i<=size; i++){
            preleft.push_back(preorder[i]);
        }
        for(int i=size+1; i<preorder.size(); i++){
            preright.push_back(preorder[i]);
        }
        
        // find the preorder & inorder of left tree
        root->left = solve(preleft, inleft);
        
        // find the preorder & inorder  of left tree
        root->right = solve(preright, inright);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder);
    }
};