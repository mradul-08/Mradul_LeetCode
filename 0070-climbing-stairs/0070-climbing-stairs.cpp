class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)return n;
    
        int pre2 = 1;
        int pre1 = 2;

        for(int i = 3; i <= n; i++){
            int curr = pre1 + pre2;
             pre2 = pre1;
            pre1 = curr;
           

        }
        return pre1;
    }
};