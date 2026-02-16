
class Solution {
public:
    TreeNode* root1;
    void parentmapping(TreeNode* root,map<TreeNode*,TreeNode*>& mpp)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
            {
                mpp[temp->left]=temp;
                q.push(temp->left);
                
            }
            if(temp->right)
            {
                mpp[temp->right]=temp;
                q.push(temp->right);
                
            }
        }
    }
    TreeNode* findinfectedroot(TreeNode* root, int start)
    {
        if(root==NULL)
            return 0;
        
        findinfectedroot(root->left,start);
        int data=root->val;
        if(data==start)
            root1=root;
        findinfectedroot(root->right,start);
        return root1;
    }
    int amnt(TreeNode* root1,map<TreeNode*,bool>& visited,int& ctr,auto& mpp)
    {
        queue<TreeNode*> q;
        q.push(root1);
        visited[root1]=true;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp=q.front();
                if(temp->left && !visited[temp->left])
                {
                    visited[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right && !visited[temp->right])
                {
                    visited[temp->right]=true;
                    q.push(temp->right);
                }
                if(mpp[temp] && !visited[mpp[temp]])
                {
                    visited[mpp[temp]]=true;
                    q.push(mpp[temp]);
                }
                q.pop();
            }
            if(!q.empty())
                ctr++;
            
        }
        return ctr;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> mpp;
        
        map<TreeNode*,bool> visited;
        parentmapping(root,mpp);
        findinfectedroot(root,start);
        int ctr=0;
        amnt(root1,visited,ctr,mpp);
        return ctr;

    }
};