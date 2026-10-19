class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        auto nRows = grid.size();
        auto nCols = grid[0].size();

        int numIslands = 0;

        for (int i = 0; i < nRows; i++) {
            for (int j=0; j < nCols; j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j, nRows, nCols);
                }
            }
        }
        return numIslands;
    }

private:
    void dfs(vector <vector<char>> &grid, int i, int j, int nRows, int nCols) {
        if ((i < 0) || (i >= nRows) || (j < 0) || (j >= nCols) || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';

        dfs(grid, i-1, j, nRows, nCols);
        dfs(grid, i+1, j, nRows, nCols);
        dfs(grid, i, j-1, nRows, nCols);
        dfs(grid, i, j+1, nRows, nCols);
    }
};
