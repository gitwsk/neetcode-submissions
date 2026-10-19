class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int maxArea = 0;
        auto nRows = grid.size();
        auto nCols = grid[0].size();

        for (int i = 0; i < nRows; i++) {
            for (int j=0; j < nCols; j++) {
                if (grid[i][j] == 1) {
                    int currArea = dfs(grid, i, j, nRows, nCols);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }

    private:
        int dfs (vector<vector<int>> &grid, int i, int j, int nRows, int nCols) {
            if ( (i < 0) || (j < 0 ) || (i >= nRows) || (j >= nCols) || grid[i][j] == 0) {
                return 0;
            }
            grid[i][j] = 0;
            int currArea = 1;
            currArea += dfs(grid, i-1, j, nRows, nCols);
            currArea += dfs(grid, i+1, j, nRows, nCols);
            currArea += dfs(grid, i, j-1, nRows, nCols);
            currArea += dfs(grid, i, j+1, nRows, nCols);
            return currArea;

        }
};