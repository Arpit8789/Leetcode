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
    int height(TreeNode* root,int& max_final_ans)
    {
        if(root==NULL)
            return 0;
        int hleft=height(root->left,max_final_ans);
        int hright=height(root->right,max_final_ans);
        int ans1=hleft+hright;
        //int ans2=max(hleft,hright)+1;
        max_final_ans=max(ans1,max_final_ans);
        return max(hleft,hright)+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int max_final_ans=0;
        height(root,max_final_ans);
        return max_final_ans;
        
    }
};