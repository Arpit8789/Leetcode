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
    int moves_count(TreeNode* root,int &moves)
    {
        if(!root) return 0;
        int a=moves_count(root->left,moves);
        int b=moves_count(root->right,moves);
        moves+=abs(a)+abs(b);
        return a+b+root->val-1;
    }
    int distributeCoins(TreeNode* root) {
        int moves=0;
        int temp=moves_count(root,moves);
        return moves;
    }
};