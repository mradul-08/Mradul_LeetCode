class Solution {
public:
    int search(vector<int>& nums, int target) {
        return f(nums, target, 0 , nums.size() -1);
    }
    int f(vector <int> & nums, int target, int st, int end){
        int mid = st + (end -st )/2;
        if(st <= end){
            if(target < nums[mid]){
                return f(nums,target, st ,mid-1);
            }
            else if( target > nums[mid]){
                return f( nums, target, mid+1, end);
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};