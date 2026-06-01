class Solution {
public:
   vector<vector<int>> dp;
bool solve(vector<int>& nums, int i, int x){
    if(x == 0){
        return true;
    }
    if(i >= nums.size()){
        return false;
    }

      if(dp[i][x] != -1)
            return dp[i][x];


    bool take = false;
    if(nums[i] <= x){
        take  = solve(nums, i+1, x-nums[i]);
    }
    bool not_take = solve(nums, i+1, x);

    return dp[i][x] =take || not_take;
}
    bool canPartition(vector<int>& nums) {
        

        int S = accumulate(nums.begin(),  nums.end(), 0);

       if(S%2 != 0){
        return false;
       }
       int target = S/2;


        int n = nums.size();

        dp.resize(n, vector<int>(target + 1, -1));

           return solve(nums, 0, target);
    }
};