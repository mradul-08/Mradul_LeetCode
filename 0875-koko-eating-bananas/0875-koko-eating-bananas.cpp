class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low <= high){
            int mid = (low+high)/2;

            long long total_hr =0;

            for(int i=0; i<piles.size(); i++){
                total_hr += ceil((double)piles[i]/mid);
            }
            if(total_hr <=h){
                ans= mid;
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }
    return ans;
    }
};