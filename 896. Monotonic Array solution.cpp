class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isInc = true;
        bool isDec = true;

        for(int i=1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
                isDec = false;
            if(nums[i] < nums[i-1])
                isInc = false;
        }

        if(isInc == true || isDec == true)
            return true;
        else
            return false;
    }
};