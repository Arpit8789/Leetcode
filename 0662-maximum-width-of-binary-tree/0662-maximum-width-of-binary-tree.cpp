
class Solution {
public:
    void solve(TreeNode* root , long long & ans)
    {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int levelSize = q.size();
            long long firstPos = q.front().second;
            long long lastPos;

            for (int i = 0; i < levelSize; i++) {
                auto [node, pos] = q.front();
                q.pop();

                pos -= firstPos;   //jaise 15 - 8 kyuki first pos already store hoga 
                lastPos = pos;

                if (node->left)
                    q.push({node->left, 2 * pos});
                if (node->right)
                    q.push({node->right, 2 * pos + 1});
            }

            ans = max(ans, lastPos + 1);
        }

    }
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        long long ans=0;
        solve(root,ans);
        return (int)ans;
        
    }
};