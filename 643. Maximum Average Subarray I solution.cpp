class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0, right = 0;
        double sum = 0, maxAvg = INT_MIN;
        int n = nums.size();

        if(n == 0)  return 0;
        if(n == 1)  return nums[0];

        while(right < n)
        {
            sum += nums[right];

            if(right - left + 1 > k)
            {
                sum -= nums[left];
                left++;
            }

            double avg = sum/k;
            if (right - left + 1 == k) {
                maxAvg = max(avg, maxAvg);
            }
            right++;
        }
        return maxAvg;
    }
};