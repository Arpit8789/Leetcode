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
    void createmapping(vector<int> inorder,map<int,int> &nodeToIndex, int n)
    {
        for(int i=0;i<n;i++)
        {
            nodeToIndex[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder , int &index,int inorderstart,int inorderEnd,int n,map<int,int> &nodeToIndex)
    {
        if(index >=n || inorderstart > inorderEnd)
        {
            return NULL;
        }

        int element = preorder[index++];
        TreeNode* root=new TreeNode(element);
        int position = nodeToIndex[element];

        root->left=solve(preorder,inorder,index,inorderstart,position-1,n,nodeToIndex);
        root->right=solve(preorder,inorder,index,position+1,inorderEnd,n,nodeToIndex);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int preOrderIndex =0;
        map<int,int> nodeToIndex;
        createmapping(inorder,nodeToIndex,n);

        TreeNode* ans=solve(preorder,inorder,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};