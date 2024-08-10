class Solution {
public:
    vector<vector<int>> moves = {
        {1,-1}, 
        {1,0}, 
        {1,1},
        {-1,-1}, 
        {-1,0}, 
        {-1,1},
        {0,-1}, 
        {0,1}
    };

    bool inboard(const vector<vector<char>>& b, int x, int y){
        return x >= 0 && x < b.size() && y >= 0 && y < b[0].size();
    }

    void dfs(vector<vector<char>>& b, int x, int y){
        if (!inboard(b, x, y)) {
            return;
        }

        int count = 0;
        if (b[x][y] == 'E') {
		    for (auto move : moves) {
				if (inboard(b, x + move[0], y + move[1]) and b[x + move[0]][y + move[1]]== 'M') {
                    count++;
                }
            }
			if (count > 0) {
                b[x][y] = '0' + count;
            }
			else {
				b[x][y] = 'B';
				for (auto move : moves) {
                    dfs(b, x + move[0], y + move[1]);
                }
			}
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        dfs(board, click[0], click[1]);
        return board;
    }
};