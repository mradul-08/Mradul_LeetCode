class Solution {
public:
    int findWays(vector<int>& nums, int tar) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

        // Base Case
        if(nums[0] == 0)
            dp[0][0] = 2;          // take or not take

        else
            dp[0][0] = 1;

        if(nums[0] != 0 && nums[0] <= tar)
            dp[0][nums[0]] = 1;

        for(int ind = 1; ind < n; ind++) {

            for(int target = 0; target <= tar; target++) {

                int notTake = dp[ind-1][target];

                int take = 0;

                if(nums[ind] <= target)
                    take = dp[ind-1][target - nums[ind]];

                dp[ind][target] = take + notTake;
            }
        }

        return dp[n-1][tar];
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int totSum = 0;

        for(auto &it : nums)
            totSum += it;

        if(totSum - target < 0)
            return 0;

        if((totSum - target) % 2 != 0)
            return 0;

        return findWays(nums, (totSum - target) / 2);
    }
};