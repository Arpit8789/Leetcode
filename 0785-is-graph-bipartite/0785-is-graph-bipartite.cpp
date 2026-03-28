class Solution {
public:
    bool check(int s, int n, vector<int>& colour, vector<vector<int>>& adj)
    {
        queue<int> q;
        q.push(s);
        
        colour[s] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it : adj[node])
            {
                if(colour[it] == -1)
                {
                    colour[it] = 1 - colour[node]; // opposite colour
                    q.push(it); // push missing
                }
                else if(colour[it] == colour[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1);

        for(int i = 0; i < n; i++)
        {
            if(colour[i] == -1)
            {
                if(check(i, n, colour, graph) == false) 
                {
                    return false;
                }
            }
        }
        return true;
    }
};