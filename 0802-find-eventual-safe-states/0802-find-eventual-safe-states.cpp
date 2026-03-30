class Solution {
public:
    bool dfs(int s,vector<vector<int>>& graph,vector<int>& visited)
    {
        visited[s]=1;
        for(auto it:graph[s])
        {
            if(!visited[it])
            {
                if(dfs(it,graph,visited)==true)
                    return true;
            }
            else if(visited[it]==1)
            {
                return true;
            }
        }
        visited[s]=2;
        
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int sz=graph.size();
        
        vector<int> ans;
        vector<int> visited(sz,0);
        for(int i=0;i<sz;i++)
        {
            if(!visited[i])
            {
                dfs(i,graph,visited);
                    
            }
        }
        for(int i=0;i<sz;i++)
        {
            if(visited[i] == 2)
                ans.push_back(i);
            
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};