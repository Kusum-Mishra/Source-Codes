class Solution {
public:
    //TC - O(NlogN + N)
    static bool comp(vector<int>& a, vector<int>& b)
    {
        return (a[1] < b[1]);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), comp); 

        int n = intervals.size();
        int count = 1;
        int lastEndtime = intervals[0][1];

        for(int i=1; i<n; i++)
        {
            if(intervals[i][0] >= lastEndtime)
            {
                count++;
                lastEndtime = intervals[i][1];
            }
        }

        return (n - count);
    }
};