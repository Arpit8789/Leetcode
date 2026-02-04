class Solution {
public:
    bool found = 0;
    bool solve(TreeNode* root, TreeNode* target, int& k, vector<int>& v) {
        if (root == NULL)
            return 0;
        found = found || root==target;
        bool l=0,r=0;
        if(found){
            k--;
            solve(root->right,target,k,v);
            solve(root->left,target,k,v);
            k++;
        }else {
        if(l=solve(root->left,target,k,v)){
            k--;
            solve(root->right,target,k,v);
            k++;
        }else if(r=solve(root->right,target,k,v)){
            k--;
            solve(root->left,target,k,v);
            k++;
        }
        }
        // if(root->val==7) cout<<k;
        if(found && k==0){
            v.push_back(root->val);
        }
        

        if (l || r || root == target)
            k--;
        return l || r || root == target;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        solve(root, target, k, ans);
        return ans;
    }
};