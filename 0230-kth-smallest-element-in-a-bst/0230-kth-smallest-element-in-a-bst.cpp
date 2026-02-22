
class Solution {
public:
    void inorder(TreeNode* root,int k,int& temp,int& ctr)
    {
        if(root==NULL)
            return;
            
        inorder(root->left,k,temp,ctr);
        
        ++ctr;
        if(ctr==k)
        {
            temp=root->val;
            return;
        }
        inorder(root->right,k,temp,ctr);
    }
    int kthSmallest(TreeNode* root, int k) {
        int temp=-1;
        int ctr=0;
        inorder(root,k,temp,ctr);
        return temp;
    }
};