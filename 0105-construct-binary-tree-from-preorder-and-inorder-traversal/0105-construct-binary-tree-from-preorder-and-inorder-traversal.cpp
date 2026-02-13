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
public:
    TreeNode* solve(vector<int>& pre, vector<int>& in,auto& mpp,int s,int e,int& beg){
        if(s>e) return 0;
        int idx=mpp[pre[beg]];
        // cout<<pre[beg]<<endl;
        TreeNode* root=new TreeNode(pre[beg++]);
        root->left=solve(pre,in,mpp,s,idx-1,beg);
        root->right=solve(pre,in,mpp,idx+1,e,beg);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        int beg=0;
        return solve(preorder,inorder,mpp,0,inorder.size()-1,beg);
    }
};