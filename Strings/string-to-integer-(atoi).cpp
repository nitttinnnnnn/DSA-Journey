// Leetcode 8: Convert string to integer following the conditions

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;
        int sign = 1;

        while (i < n && isspace(s[i])){
            i++;
        }
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '+'){
                sign = 1;
                i++;
            }
            else{
                sign = -1;
                i++;
            }
        }
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            if (sign == 1 && result > INT_MAX){
                return INT_MAX;
            }    
            if (sign == -1 && -result < INT_MIN){
                return INT_MIN;
            }    
            i++;
        }

        return (int)(sign * result);
    }
};
