class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ' ') continue;

            int j = i;
            while(j >= 0 && s[j] != ' ') j--;

            for(int k = j + 1; k <= i; k++) ans += s[k];
            ans += ' ';

            i = j;
        }

        if(!ans.empty()) ans.pop_back();
        return ans;
    }
};