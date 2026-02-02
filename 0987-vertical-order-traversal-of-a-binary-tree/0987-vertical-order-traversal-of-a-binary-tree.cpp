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

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode* , pair<int,int>>> q;
        int row=0,col=0;
        q.push(make_pair(root,make_pair(row,col)));
        //TreeNode* temp;
        map<int , map<int,vector<int>>> mpp;
        while(!q.empty())
        {
            auto temp=q.front();
            
            auto nod=temp.first;
            q.pop();
            row=temp.second.first;
            col=temp.second.second;
            mpp[col][row].push_back(nod->val);
            if(nod->left)
                q.push(make_pair(nod->left,make_pair(row+1,col-1)));
            if(nod->right)
                q.push(make_pair(nod->right,make_pair(row+1,col+1)));
        }
        
        for (auto &colPair : mpp)
        {
            vector<int> column;

            for (auto &rowPair : colPair.second)
            {
                sort(rowPair.second.begin(), rowPair.second.end());

                for (int val : rowPair.second)
                {
                    column.push_back(val);
                }
            }

            ans.push_back(column);
        }

        return ans;
    }
};