class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Store rows and columns that need to be zeroed
        unordered_set<int> zeroRows, zeroCols;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        // Step 2: Update matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (zeroRows.count(i) || zeroCols.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
