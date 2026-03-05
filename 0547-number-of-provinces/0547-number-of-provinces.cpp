class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<int>& vis,vector<int>& ans,int src,int n)
    {
        ans.push_back(src);
        vis[src]=1;
       
        for(int m=0;m<n;m++)
        {
            if(isConnected[src][m])
            {
                if(!vis[m])
                {
                    dfs(isConnected,vis,ans,m,n);
                   
                }
            }
        }
            
            
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        vector<int> ans;
        int ctr=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ctr++;
                dfs(isConnected,vis,ans,i,n);
            }
        }
        
        return ctr;
        
    }
};