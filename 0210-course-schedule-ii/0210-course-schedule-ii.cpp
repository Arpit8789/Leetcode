class Solution {
public:
    bool dfs(int s,vector<vector<int>>& adj,vector<int>& visited,stack<int>& st)
    {
        visited[s]=1;
        for(auto it:adj[s])
        {
            if(!visited[it])
            {
                if(dfs(it,adj,visited,st)==true)
                    return true;
            }
            else if(visited[it]==1)
            {
                return true;
            }
        }
        visited[s]=2;
        st.push(s);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites)
        {
            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
        }
        stack<int> st;
        vector<int> ans;
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited,st)==true)
                    return {};
            }
        }
        while(!st.empty())
        {
            int temp=st.top();
            st.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};