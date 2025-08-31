class Solution {
public:
    //APPROACH 1 (brute) - O(n^3) - acceptable here because constraints are not much strong
    /*int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        if(n == 1)
            return 1;

        for(int i=0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int count = 2;
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                
                for(int k=0; k < n; k++)
                {
                    if(k != i && k != j)
                    {
                        int dx_ = points[k][0] - points[i][0];
                        int dy_ = points[k][1] - points[i][1];

                        if(dy * dx_ == dx * dy_)
                            count++;
                    }
                }

                result = max(result, count);
            }
        }

        return result;
    }*/

    //APPROACH 2 (using atan2) - O(n^2)
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        if(n == 1)
            return 1;

        for(int i=0; i < n; i++)
        {
            unordered_map<double, int> mpp;
            for(int j=0; j < n; j++)
            {
                if(j == i)
                    continue;

                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                
                auto theta = atan2(dy, dx);
                mpp[theta]++;
            }

            for(auto& it : mpp)
            {
                result = max(result, it.second + 1);
            }
        }

        return result;
    }

    /*//APPROACH 3 (without using atan2) - O(n^2)
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        if(n == 1)
            return 1;

        for(int i=0; i < n; i++)
        {
            unordered_map<string, int> mpp;
            for(int j=0; j < n; j++)
            {
                if(j == i)
                    continue;

                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];

                int gcd = __gcd(dy, dx);
                
                string key = to_string(dx/gcd) + "_" + to_string(dy/gcd);
                mpp[key]++;
            }

            for(auto& it : mpp)
            {
                result = max(result, it.second + 1);
            }
        }
        return result;
    }*/
};