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
    void level(TreeNode* root,int& ctr)
    {
        queue<TreeNode*> q;
        TreeNode* temp;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            else
            {
                ctr++;
                if(!q.size())
                    return;
                else
                    q.push(NULL);
                
            }
            
        }

    }
    int maxDepth(TreeNode* root) {
        int ctr=0;
        if(root==NULL)
            return ctr;
        level(root,ctr);
        return ctr;
    }
};