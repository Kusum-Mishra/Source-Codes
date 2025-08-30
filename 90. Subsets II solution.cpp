class Solution {
public:
    //Total TC = O(nlogn + n*2^n)
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int index, vector<vector<int>>& allSubsets)
    {
        if(index == nums.size())
        {
            allSubsets.push_back(ans);
            return;
        }

        ans.push_back(nums[index]);
        getAllSubsets(nums, ans, index + 1, allSubsets);
        ans.pop_back();

        int pos = index + 1;
        while(pos < nums.size() && nums[pos] == nums[pos-1])
            pos++;
        
        getAllSubsets(nums, ans, pos, allSubsets);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};