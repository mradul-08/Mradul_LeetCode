class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allSubsets) {

        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i+1, allSubsets);

        ans.pop_back();

        getAllSubsets(nums, ans, i+1, allSubsets);
    } 

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};