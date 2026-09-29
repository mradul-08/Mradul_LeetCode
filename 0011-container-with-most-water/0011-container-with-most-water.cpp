class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_water = 0;
        int lp = 0;
        int rp = n-1;

        while(lp < rp){
            int width = rp - lp;
               int height_1 = min(height[lp], height[rp]);
            int curr_water = width * height_1;

            max_water = max(curr_water, max_water);

            height[lp] < height[rp] ? lp++ : rp--;
        }
        return max_water;
    }
};