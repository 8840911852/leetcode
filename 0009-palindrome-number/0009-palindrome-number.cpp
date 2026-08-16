class Solution {
public:
    bool isPalindrome(int n) {
        if(n < 0) {
            return false;
        }

        int original = n;
        long long num = 0;

        while(n != 0) {
            int digit = n % 10;
            num = num * 10 + digit;
            n = n / 10;
        }

        if(original == num) {
            return true;
        }

        return false;
    }
};
