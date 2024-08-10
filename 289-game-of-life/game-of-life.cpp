class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> moves = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1}
        };

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] % 2 == 1) {
                    int neigh = 0;
                    for (auto move : moves) {
                        if (row + move[0] >= 0 
                        && row + move[0] < board.size() 
                        && col + move[1] >= 0 
                        && col + move[1] < board[0].size()
                        && board[row + move[0]][col + move[1]] % 2 == 1) {
                            neigh++;
                        }
                    }
                    cout << neigh << "\n";
                    if (neigh == 2 || neigh == 3) {
                        board[row][col] += 2;
                    }
                }
                if (board[row][col] % 2 == 0) {
                    int neigh = 0;
                    for (auto move : moves) {
                        if (row + move[0] >= 0 
                        && row + move[0] < board.size() 
                        && col + move[1] >= 0 
                        && col + move[1] < board[0].size()
                        && board[row + move[0]][col + move[1]] % 2 == 1) {
                            neigh++;
                        }
                    }
                    cout << neigh << "\n";
                    if (neigh == 3) {
                        board[row][col] += 2;
                    }
                }
            }
        }
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                board[row][col] /= 2;
            }
        }
    }
};