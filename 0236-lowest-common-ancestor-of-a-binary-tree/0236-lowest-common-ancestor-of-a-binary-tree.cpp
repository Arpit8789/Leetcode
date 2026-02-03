class Solution {
    bool gotP = false;
    bool gotQ = false;

public:
    void solve(TreeNode* root, TreeNode* p, TreeNode* q,
               vector<vector<TreeNode*>>& ans,
               vector<TreeNode*>& v)
    {
        if (root == NULL)
            return;

        v.push_back(root);

        if (root == p && !gotP) {
            ans.push_back(v);
            gotP = true;
        }

        if (root == q && !gotQ) {
            ans.push_back(v);
            gotQ = true;
        }

        solve(root->left, p, q, ans, v);
        solve(root->right, p, q, ans, v);

        v.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;

        vector<vector<TreeNode*>> ans;
        vector<TreeNode*> v;

        solve(root, p, q, ans, v);

        if (ans.size() == 1)
            return ans[0].back();   

        if (ans.size() < 2)
            return NULL;

        TreeNode* lca = NULL;
        int sz = min(ans[0].size(), ans[1].size());

        for (int i = 0; i < sz; i++) {
            if (ans[0][i] == ans[1][i])
                lca = ans[0][i];
            else
                break;
        }

        return lca;
    }
};
