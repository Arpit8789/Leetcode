class Solution {
public:
    bool isnotrotten(vector<vector<int>>& grid,int r,int c)
    {
        if(r>=0 && c>=0)
        {
            if(r<grid.size() && c<grid[0].size() && grid[r][c]==1)
            {
                grid[r][c]=2;
                return true;
            }
        }
        
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int dx[4] = {1,-1,0,0};
        int dy[4]= {0,0,1,-1};
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }
            }
        }
        int minutes=0;
        pair<int,int> temp;
        
        while(!q.empty())
        {
            bool changed = false;
            int size=q.size();
            while(size--)
            {
                temp=q.front();
                q.pop();
                int r=temp.first;
                int c=temp.second;
                for(int k=0;k<4;k++)
                {
                    if(isnotrotten(grid,r+dx[k],c+dy[k]))
                    {
                        changed= true;
                        q.push(make_pair(r+dx[k],c+dy[k]));
                    }
                }
            }
            if(changed == true)
            {
                minutes++;
            }
            
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return minutes;
    }
    
};