class Solution {
public:
    //Time: O(n)
    //Space: O(min(n, k))
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(window.count(nums[i]))
                return true;

            window.insert(nums[i]);

            if(i >= k)
                window.erase(nums[i-k]);
        }
        return false;
    }
};