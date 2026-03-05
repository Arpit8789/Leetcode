class Solution {
public:

    void dfs(vector<vector<int>>& adj,vector<int>& vis,int src,int& nnodes,int& nedges)
    {
        vis[src]=1;
        for(auto it:adj[src])
        {
            nedges++;
            if(!vis[it])
            {
                nnodes++;
                dfs(adj,vis,it,nnodes,nedges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        int nnodes=1,nedges=0,cnt=0;
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(adj,vis,i,nnodes,nedges);
                
                if((nedges/2)==(nnodes*(nnodes-1)/2 ))
                    cnt++;
                nnodes=1,nedges=0;
            }
        }
        
        return cnt;
    }
};