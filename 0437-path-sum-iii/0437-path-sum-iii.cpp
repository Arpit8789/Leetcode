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
    int count=0;
    vector<int> path;
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return count;
        path.push_back(root->val);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        int sz=path.size();
        long long sum=0;
        for(int i=sz-1;i>=0;i--)
        {
            sum+=path[i];
            
            if(sum==targetSum)
                count++;
        }
        path.pop_back();
        return count;

        
    }
};