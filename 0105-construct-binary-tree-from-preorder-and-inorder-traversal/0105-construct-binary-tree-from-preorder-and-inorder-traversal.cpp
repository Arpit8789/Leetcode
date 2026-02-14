
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, map<int,int>& mpp,int s,int e,int& i)
    {
        if(s>e)
            return 0;
        int rootindx = mpp[preorder[i]];
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left=solve(preorder,inorder,mpp,s,rootindx-1,i);
        root->right=solve(preorder,inorder,mpp,rootindx+1,e,i);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        int i=0;
        TreeNode* root=solve(preorder,inorder,mpp,0,inorder.size()-1,i);
        return root;
    }
};