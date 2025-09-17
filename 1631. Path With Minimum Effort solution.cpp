class Solution {
public:
    //TC - ElogV
    //SC - (m*n)
    vector<vector<int>> directions{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;

        pq.push({0, {0, 0}});

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == m-1 && col == n-1)
                return diff;

            for(auto& dir : directions){
                int new_r = row + dir[0];
                int new_c = col + dir[1];

                if(new_r >= 0 && new_c >= 0 && new_r < m && new_c < n)
                {
                    int newEffort = max(diff, abs(heights[row][col] - heights[new_r][new_c]));
                    if(newEffort < dist[new_r][new_c])
                    {
                        dist[new_r][new_c] = newEffort;
                        pq.push({newEffort, {new_r, new_c}});
                    }
                }
            }
        }

        return 0;
    }
};