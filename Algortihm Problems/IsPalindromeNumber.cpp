#include <iostream>
class Solution {
private:
    static int reversedNumber(int x){
        int remainder, rev = 0;
        while (x != 0) {
            remainder = x % 10;
            rev = rev * 10 + remainder;
            x /= 10;
        }
        return rev;   
    }
public:
    static bool isPalindrome(int x) {
        if(x<0 ||(x%10==0 && x!=0))
            return false;
        int rev = reversedNumber(x);
        return rev == x;
    }
};
