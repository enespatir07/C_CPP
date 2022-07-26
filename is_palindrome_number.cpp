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

int main() {
    int input;
    std::cout << "Please enter the number to learn if it is a palindrome: ";
    std::cin >> input;
    if (Solution::isPalindrome(input))
        std::cout << input << " is a palindrome" << std::endl;
    else
        std::cout << input << " is not a palindrome" << std::endl;
}
