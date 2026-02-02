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
    void symmetry(TreeNode* rootl,TreeNode* rootr,bool& flag)
    {
        if(rootl==NULL && rootr==NULL)
            return;
        if(rootl!=NULL && rootr==NULL)
        {
            flag=false;
            return;
        }
        if(rootl==NULL && rootr!=NULL)
        {
            flag=false;
            return;
        }
        if(rootl->val!=rootr->val)
        {
            flag=false;
            return;
        }
        symmetry(rootl->left,rootr->right,flag);
        symmetry(rootl->right,rootr->left,flag);
    }
    bool isSymmetric(TreeNode* root) {
        bool flag=true;
        if(root==NULL)
            return flag;
        symmetry(root->left,root->right,flag);
        return flag;
    }
};