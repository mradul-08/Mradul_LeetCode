class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int l = s.length();

        while(i<l && isspace(s[i])){
            i++;
        }
        if(i == l){
            return 0;
        }
        bool negative = false;
        if( s[i] == '-'){
           negative = true;
           i++; 
        }
        else if( s[i] == '+'){
            i++;
        }

        else if( !isdigit(s[i]) ){
            return 0;
        }

        if( i== l ){
            return 0;
        }
        while( i<l && s[i] == '0') {
          i++;  
        }

        if(i == l){
            return 0;
        }

        int value = 0;
        int max = INT_MAX/10;
        int min = INT_MIN/10;
        while( i<l && isdigit(s[i] )){
            int digit = s[i] - '0';

            if( value> max){
                return INT_MAX;
            }
            else if ( value == max && digit> 7){
                return INT_MAX;
            }
             if( value < min){
                return INT_MIN;
            }
            else if ( value == min && digit> 8){
                return INT_MIN;
            }

            if( negative ){
                value = value*10 + (-digit);

            }
            else{
                value = value*10 + digit;
            }
            i++;
        }
       return value; 
    }
};