class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        // row check
        for (int i = 0; i < n; i++) {
            vector<bool> row(9, false);
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') continue;
                if (row[board[i][j] - '1'])
                    return false;
                else
                    row[board[i][j] - '1'] = true;
            }
        }
        // col check
        for (int i = 0; i < m; i++) {
            vector<bool> col(9, false);
            for (int j = 0; j < n; j++) {
                if (board[j][i] == '.') continue;
                if (col[board[j][i] - '1'])
                    return false;
                else
                    col[board[j][i] - '1'] = true;
            }
        }
        // box check
        for (int i = 0; i < m; i += 3) {
            for (int j = 0; j < n; j += 3) {
                vector<bool> box(9, false);
                for (int s = i; s < i + 3; s++) {
                    for (int e = j; e < j + 3; e++) {
                        if (board[s][e] == '.') continue;
                        if (box[board[s][e] - '1'])
                            return false;
                        else
                            box[board[s][e] - '1'] = true;
                    }
                }
            }
        }
        return true;
    }
};
