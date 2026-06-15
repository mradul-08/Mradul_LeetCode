class Solution {
public:
    bool divisorGame(int n) {
        for(int x = 1; x <=n ; x++){
        if(n <= 1){
            return false;
        }
        if(n%x == 0 ){
            return !divisorGame(n-x);
        }
    }
    return false;
    }
};