
class Solution {
public:
    TreeNode* solve(TreeNode* root,int t)
    {
        if(root==NULL)
            return 0;
        if(root->val==t)
        {
            return root;
        }
        else if(root->val<t)
        {
            return solve(root->right,t);
        }
        else
        {
            return solve(root->left,t);
        }
        return root;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* root1=solve(root,val);
        return root1;
    }
};