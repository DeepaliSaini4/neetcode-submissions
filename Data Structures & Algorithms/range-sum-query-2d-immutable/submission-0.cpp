class NumMatrix {
   public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        pre = vector<vector<int>>(n, vector<int>(m));
        // making of prefix sum O(n*m)
        pre[0][0] = matrix[0][0];
        for (int i = 1; i < m; i++) pre[0][i] = matrix[0][i] + pre[0][i - 1];
        for (int j = 1; j < n; j++) pre[j][0] = matrix[j][0] + pre[j - 1][0];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                pre[i][j] = (matrix[i][j] + pre[i - 1][j] + pre[i][j - 1]) - pre[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = pre[row2][col2];
        if (row1 > 0) {
            ans -= pre[row1 - 1][col2];
        }
        if (col1 > 0) ans -= pre[row2][col1 - 1];
        if (col1 > 0 && row1 > 0) ans += pre[row1 - 1][col1 - 1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */