class Solution {
public:

    void parentmapping(TreeNode* root, map<TreeNode*, TreeNode*>& mpp) {
        if (root == NULL)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp->left) {
                mpp[temp->left] = temp;
                q.push(temp->left);
            }

            if (temp->right) {
                mpp[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    void distancemoving(TreeNode* target,
                        int k,
                        vector<int>& ans,
                        map<TreeNode*, TreeNode*>& mpp)
    {
        queue<TreeNode*> q;
        q.push(target);

        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;

        int ctr = 0;

        while (!q.empty())
        {
            int size = q.size();

            if (ctr == k)
            {
                while (!q.empty())
                {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return;
            }

            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left && !visited[temp->left])
                {
                    visited[temp->left] = true;
                    q.push(temp->left);
                }

                if (temp->right && !visited[temp->right])
                {
                    visited[temp->right] = true;
                    q.push(temp->right);
                }

                if (mpp[temp] && !visited[mpp[temp]])
                {
                    visited[mpp[temp]] = true;
                    q.push(mpp[temp]);
                }
            }

            ctr++;   // increment AFTER finishing one level
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        map<TreeNode*, TreeNode*> mpp;
        parentmapping(root, mpp);

        vector<int> ans;
        distancemoving(target, k, ans, mpp);

        return ans;
    }
};
