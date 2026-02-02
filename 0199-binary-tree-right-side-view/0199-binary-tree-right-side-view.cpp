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
    void levelorder(TreeNode* root , vector<int>& ans)
    {
        TreeNode* temp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int levelsize=q.size();
            for(int i=0;i<levelsize;i++)
            {
                temp=q.front();
                q.pop();
                if(i==levelsize-1)
                    ans.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            
            
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        levelorder(root,ans);
        return ans;
    }
};