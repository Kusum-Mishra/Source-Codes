class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int result = 0;

        for(int i=0; i<n; i++)
            mpp[nums[i]]++;

        for(int i=0; i<n; i++)
        {
            int minNum = nums[i];
            int maxNum = nums[i] + 1;
            if(mpp.find(maxNum) != mpp.end())
            {
                result = max(result, mpp[minNum] + mpp[maxNum]);
            }
        }

        return result;
    }
};