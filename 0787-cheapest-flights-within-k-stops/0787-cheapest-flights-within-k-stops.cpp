class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // queue: {stops, {node, cost}}
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}});
        
        // distance array
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            
            int stops = temp.first;
            int node = temp.second.first;
            int cost = temp.second.second;
            
            // if stops exceed k, skip
            if(stops > k) continue;
            
            for(auto &it : adj[node])
            {
                int nextNode = it.first;
                int price = it.second;
                
                if(cost + price < dist[nextNode] && stops <= k)
                {
                    dist[nextNode] = cost + price;
                    q.push({stops + 1, {nextNode, dist[nextNode]}});
                }
            }
        }
        
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};