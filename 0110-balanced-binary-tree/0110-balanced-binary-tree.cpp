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
    pair<bool,int> fastbalanced(TreeNode* root)
    {
        if(root == NULL)
            return {true,0};

        pair<int,int> left =fastbalanced(root->left);
        pair<int,int> right =fastbalanced(root->right);

        bool leftdiff=left.first;
        bool rightdiff=right.first;

        bool diff=abs(left.second-right.second)<=1;
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        if(leftdiff && rightdiff && diff)
        {
            ans.first=true;
        }
        else
        {
            ans.second=false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return fastbalanced(root).first;
    }
};