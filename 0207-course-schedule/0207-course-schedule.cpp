class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        int cnt=0;
        for(auto it : prerequisites)
        {
            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
        }
        vector<int> indegree(numCourses);
        for(auto it:adj)
        {
            for(auto it1:it)
            {
                indegree[it1]++;
            }
            
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[temp])
            {  
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }

        if(cnt==numCourses)
            return true;
        else
            return false;
    }
};