class Solution {
public:
    bool isvisited(vector<vector<int>>& mat,int r,int c,int parent)
    {
        if(r>=0 && c>=0)
        {
            if(r < mat.size() && c < mat[0].size())
            {
                if(mat[r][c] == -1)
                {
                    mat[r][c] = parent + 1;   
                    return true;
                }
            }
        }
        return false;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push(make_pair(i,j));
                }
                else
                {
                    mat[i][j]=-1;
                }
            }
        }

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        int parent=0;
        pair<int,int> temp;

        while(!q.empty())
        {
            temp=q.front();
            q.pop();

            int r=temp.first;
            int c=temp.second;

            parent = mat[r][c];

            for(int i=0;i<4;i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(isvisited(mat,nr,nc,parent))
                {
                    q.push(make_pair(nr,nc));
                }
            }
        }

        return mat;
    }
};