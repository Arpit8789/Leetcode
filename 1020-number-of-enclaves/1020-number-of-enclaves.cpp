
class Solution {
public:
    bool isvisited(vector<vector<int>>& grid, int r, int c) {
        if (r >= 0 && c >= 0) {
            if (r < grid.size() && c < grid[0].size()) {
                if (grid[r][c] == -1) {

                    return true;
                }
            }
        }
        return false;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[0][i] == 1) {
                q.push(make_pair(0, i));
            }
            if (grid[grid.size() - 1][i] == 1) {
                q.push(make_pair(grid.size() - 1, i));
            }
        }
        for (int i = 1; i < grid.size() - 1; i++) {
            if (grid[i][0] == 1) {
                q.push(make_pair(i, 0));
            }
            if (grid[i][grid[0].size() - 1] == 1) {
                q.push(make_pair(i, grid[0].size() - 1));
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                }
            }
        }
        // cout<<q.size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        pair<int, int> temp;
        while (!q.empty()) {
            temp = q.front();
            q.pop();

            int r = temp.first;
            int c = temp.second;
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                grid[r][c] = 1;
                if (isvisited(grid, nr, nc)) {
                    grid[nr][nc] = 1;
                    q.push(make_pair(nr, nc));
                }
            }
        }
        int ctr=0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] ==-1) {
                    ctr++;
                }
            }
        }
        return ctr;
    }
};