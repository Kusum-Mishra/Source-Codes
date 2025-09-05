class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> st;
        int n = nums.size();

        for(int i = 0; i<n; i++)
        {
            if(nums[i] > 0)
                st.push_back(nums[i]);
            else
            {
                while(!st.empty() && st.back() > 0 && st.back() < abs(nums[i]))
                    st.pop_back();

                if(!st.empty() && st.back() == abs(nums[i]))
                    st.pop_back();
                else if(st.empty() || st.back() < 0)
                    st.push_back(nums[i]);
            }
        } 
        return st;
    }
};