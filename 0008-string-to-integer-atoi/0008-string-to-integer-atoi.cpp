class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()){
            return 0;
        }

        int len = s.length(), i = 0, sign = 1;

        while(i < len && s[i] == ' '){
            i++;
        }

        if(i == len){
            return 0;
        }

        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }

        long int out = 0;

        while(i < len && s[i] >= '0' && s[i] <= '9'){
            out = out * 10 + (s[i] - '0');

            if(out > INT_MAX){
                break;
            }

            i++;
        }

        if(sign == -1){
            out = -out;
        }

        if(out < INT_MIN){
            return INT_MIN;
        }

        if(out > INT_MAX){
            return INT_MAX;
        }

        return (int)out;
    }
};