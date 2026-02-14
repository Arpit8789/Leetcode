
class Solution {
public:
    TreeNode* solve( vector<int>& postorder,vector<int>& inorder, map<int,int>& mpp,int s,int e,int& i)
    {
        if(s>e)
            return 0;
        int rootindx=mpp[postorder[i]];
        TreeNode* root=new TreeNode(postorder[i]);
        i--;
        root->right=solve(postorder,inorder,mpp,rootindx+1,e,i);
        root->left=solve(postorder,inorder,mpp,s,rootindx-1,i);
        
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
       
        int sz= postorder.size();
         int i=sz-1;
        TreeNode* root=solve(postorder,inorder,mpp,0,inorder.size()-1,i);
        return root;
        
    }
};