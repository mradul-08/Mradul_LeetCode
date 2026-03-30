class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxi = 0;
        for(int i = 0; i< s.size(); i++){
            if(s[i] == '('){
                depth ++;
                maxi = max(maxi, depth);
            }
            else if (s[i] == ')'){
                depth --;
            }
            
                           
        
        }
        return maxi;
    }
};