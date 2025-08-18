class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 1. Check each row
        for (int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    if (seen.count(c)) return false; // duplicate found
                    seen.insert(c);
                }
            }
        }

        // 2. Check each column
        for (int j = 0; j < 9; j++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                char c = board[i][j];
                if (c != '.') {
                    if (seen.count(c)) return false;
                    seen.insert(c);
                }
            }
        }

        // 3. Check each 3x3 sub-box
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_set<char> seen;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[boxRow + i][boxCol + j];
                        if (c != '.') {
                            if (seen.count(c)) return false;
                            seen.insert(c);
                        }
                    }
                }
            }
        }

        return true; // passed all checks
    }
};
