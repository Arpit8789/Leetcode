
class Solution {
public:
    TreeNode* solve(TreeNode* root,int k)
    {
        if(root->left==NULL && root->val>k)
        {
            root->left=new TreeNode(k);
            return root;
        }
        if(root->right==NULL && root->val<k)
        {
            root->right=new TreeNode(k);
            return root;
        }
        if(root->val>k)
            return solve(root->left,k);
        else
            return solve(root->right,k);
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
        {
            root=new TreeNode(val);
            return root;
        }
             
        solve(root,val);
        return root;
    }
};