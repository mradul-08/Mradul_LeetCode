class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int balance = 0;
        for(int i = 0; i< s.size(); i++){
            char ch = s[i];
            if(ch == '('){
                if(balance >0){
                    ans += ch;
                }
              balance++;
            }
            else {
                  balance--;
                if(balance >0){
                     ans += ch;
                }
               
            }
           
        }
        if(balance != 0){
            return "Invalid String";
        }
        return ans;
    }
};