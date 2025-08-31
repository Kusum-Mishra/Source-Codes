class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i=0; i < n; i++)
        {
            int more = target - nums[i];

            if(mpp.find(more) != mpp.end())
            {
                return {mpp[more], i};
            }

            mpp[nums[i]] = i;
        }
        return {};
    }
};