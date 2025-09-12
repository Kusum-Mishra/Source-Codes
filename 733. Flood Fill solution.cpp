class Solution {
public:
    //TC - O(m * n)
    //SC - O(m * n)
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, int iniColor)
    {
        ans[row][col] = newColor;
        int m = image.size();
        int n = image[0].size();

        for(auto& dir : directions)
        {
            int new_row = row + dir[0];
            int new_col = col + dir[1];

            if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && image[new_row][new_col] == iniColor && ans[new_row][new_col] != newColor){
                dfs(new_row, new_col, ans, image, newColor, iniColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;

        dfs(sr, sc, ans, image, color, iniColor);
        return ans;
    }
};