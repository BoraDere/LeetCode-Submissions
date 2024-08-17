class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m = heights.size();
        int n = heights[0].size();

        if (m == 0 || n == 0) {
            return res;
        }

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for(int col = 0; col < n; col++) {
            search(0, col, pac, heights[0][col], heights);                    
            search(m-1, col, atl, heights[m-1][col], heights);          
        }

        for(int row = 0; row < m; row++) {
            search(row, 0, pac, heights[row][0], heights);              
            search(row, n-1, atl, heights[row][n-1], heights);    
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

private:
    vector<vector<int>> dirs = {
        {1,0}, 
        {-1,0}, 
        {0,-1}, 
        {0,1}
    };

    void search(int row, int col, vector<vector<bool>>& visit, int preHeight, vector<vector<int>>& heights) {
        if (row < 0 || col < 0 || row == heights.size() || col == heights[0].size() || visit[row][col] || preHeight>heights[row][col]) {
            return;
        }

        visit[row][col]=true;

        for (auto dir : dirs) {
            search(row + dir[0], col + dir[1], visit, heights[row][col], heights);
        }
    }
};