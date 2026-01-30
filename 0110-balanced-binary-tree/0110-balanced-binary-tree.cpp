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
    int height(TreeNode* root,bool& flag)
    {
        
        if(root==NULL)
        {
            return -1;
        }
        if(flag==false)
            return 0;
        int hleft=height(root->left,flag);
        int hright=height(root->right,flag);
        if(abs(hleft-hright)>1)
        {
            flag=false;
            return 0;
        }
        else
            return max(hleft,hright)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        bool flag=true;
        height(root,flag);
        return flag;
        
    }
};