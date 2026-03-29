class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char, int>freq;

       for(int i = 0 ; i<s.size(); i++){
        char ch = s[i];
        freq[ch] = freq[ch] +1 ;
       } 

       vector<pair<char, int>> vec;
       for(auto it = freq.begin(); it != freq.end(); it++){
        vec.push_back(*it);
       }
       sort(vec.begin(), vec.end(), [](pair<char,int> a, pair<char,int> b){
            return a.second > b.second;
    });

    string result = "";

    for(int i = 0; i < vec.size(); i++) {
            char ch = vec[i].first;
            int count = vec[i].second;

            for(int j = 0; j < count; j++) {
                result += ch;
            }
        }

        return result;
    }
};