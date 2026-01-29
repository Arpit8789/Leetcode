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
    void lev(auto root, auto& ans)
    {
        queue<TreeNode*> q;
        vector<int> v;
        TreeNode* temp;
        q.push(root);
        q.push(0);
        
        while(!q.empty())
        {
            temp=q.front(); q.pop();
            if(temp!=0){
                v.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }else{
                ans.push_back(v);
                v.clear();
                if(q.empty()) return;
                q.push(0);
            }
   
        }
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        lev(root,ans);
        return ans;
    }
};