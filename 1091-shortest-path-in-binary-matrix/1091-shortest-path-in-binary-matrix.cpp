class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        // edge case
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        
        // 8 directions
        vector<int> dx = {-1,-1,-1,0,0,1,1,1};
        vector<int> dy = {-1,0,1,-1,1,-1,0,1};
        
        // queue for BFS
        queue<pair<int,int>> q;
        
        // start
        q.push({0,0});
        grid[0][0] = -1;   // mark visited
        
        int steps = 1;
        
        // YOU CONTINUE FROM HERE 👇
        while(!q.empty())
        {
            
            int sz=q.size();
            while(sz--)
            {
                auto temp=q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
                if(x == n-1 && y == n-1)
                    return steps;
                for(int k = 0; k < 8; k++)
                {
                    int new_x = x + dx[k];
                    int new_y = y + dy[k];
                    if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < n)
                    {
                        if(grid[new_x][new_y]==0)
                        {
                            q.push({new_x,new_y});
                            grid[new_x][new_y]=-1;
                        }
                        
                    }
                    
                }
                
            }
            steps++;
            
        }
        
        return -1;
    }
};