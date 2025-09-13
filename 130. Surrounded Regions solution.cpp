class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<char>>& board, int row, int col)
    {
        int m = board.size();
        int n = board[0].size();
        board[row][col] = '#';

        for(auto& dir : directions)
        {
            int new_r = row + dir[0];
            int new_c = col + dir[1];
            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && board[new_r][new_c] == 'O'){
                dfs(board, new_r, new_c);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        if(m == 0) return;
        
        for(int i=0; i<m; i++)
        {
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][n-1] == 'O')
                dfs(board, i, n-1);
        }

        for(int j=0; j<n; j++)
        {
            if(board[0][j] == 'O')
                dfs(board, 0, j);
            if(board[m-1][j] == 'O')
                dfs(board, m-1, j);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};