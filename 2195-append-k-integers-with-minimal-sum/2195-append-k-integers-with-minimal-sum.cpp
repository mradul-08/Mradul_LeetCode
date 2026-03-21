class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int i = 0;
        int number = 1;
        int missing = 0;
        long long minimum_sum = 0;

        set<int> st(nums.begin(), nums.end());
        vector<int> sortedNums(st.begin(), st.end());

        while(missing < k){
            if(i < sortedNums.size() && sortedNums[i] == number){
                i++;
            }
            else{
                missing++;
                minimum_sum += number;
            }
            number++;
        }

        return minimum_sum;
    }
};