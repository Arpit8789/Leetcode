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
    void levelorder(TreeNode* root, vector<vector<int>>& ans)
    {
        queue<TreeNode*> q;
        TreeNode* temp;
        vector<int> v;
        q.push(root);
        q.push(NULL);
        int ctr=0;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
                v.push_back(temp->val);
                if(temp->right)
                    q.push(temp->right);
                if(temp->left)
                    q.push(temp->left);
            }
            else
            {
                if(ctr%2==0)
                    reverse(v.begin(),v.end());
                ans.push_back(v);
                if(q.size())
                    q.push(NULL);
                else
                    return;
                v.clear();
                ctr++;
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        levelorder(root,ans);
        return ans;
    }
};