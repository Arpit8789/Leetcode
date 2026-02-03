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
    void solve(TreeNode* root,vector<vector<int>>& ans,vector<int>& v)
    {
        
        if(root==NULL)
            return;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(v);
            v.pop_back();
            return;
        }
        solve(root->left,ans,v);
        solve(root->right,ans,v);
        v.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<string> st;
        // string str;
        solve(root,ans,v);
        for (auto it:ans)
        {
            string str="";
            for(auto itt:it)
            {
                str += to_string(itt);

                str+="->";
            }
            str.pop_back();
            str.pop_back();
            st.push_back(str);
        }
        return st;
    }
};