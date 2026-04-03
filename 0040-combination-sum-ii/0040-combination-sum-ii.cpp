class Solution {
public:

void findCombination(int ind,vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &ds){
    sort(arr.begin(), arr.end());
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    for(int i = ind; i<arr.size();i++){
        if(i> ind && arr[i] == arr[i-1])continue;
        if(arr[i] > target)break;
        ds.push_back(arr[i]);
        findCombination(i+1, arr,target - arr[i], ans, ds);
ds.pop_back();
    }

}
    vector<vector<int>> combinationSum2(vector<int>&arr, int target) {
       vector<vector<int>>ans;
       vector<int>ds;

       findCombination(0, arr,target, ans,ds);
       return ans;

    }
};