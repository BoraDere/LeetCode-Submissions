class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(i, j, 0, word, board, m, n)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(int i, int j, int idx, string word, vector<vector<char>>& board, int m, int n) {
        if (idx == word.length()) {
            return true;
        }

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j];
            board[i][j] = '0';
            
            if (backtrack(i + 1, j, idx + 1, word, board, m, n) || backtrack(i - 1, j, idx + 1, word, board, m, n) || 
                backtrack(i, j + 1, idx + 1, word, board, m, n) || backtrack(i, j - 1, idx + 1, word, board, m, n)) {
                return true;
            }
            
            board[i][j] = temp; 
            return false;
    }
};