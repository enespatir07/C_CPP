#include <iostream>
using std::string;
class Solution {
private:
    static bool isAnagram(string s, string t) {
        int flag = 0;
        if (s.length() != t.length())//check if lengths match
            return false;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < t.length(); j++) {
                if (s[i] == t[j]) {
                    t.erase(j, 1);//matched chars in string t will be erased
                    flag++;
                    break;
                }
            }
        }
        return flag == s.length();
    }

public:
    static void main() {
        string str1, str2;
        std::cout << "Enter two strings to find out if they are anagram:" << std::endl;
        std::cin >> str1;
        std::cin >> str2;
        if (isAnagram(str1, str2))
            std::cout << str1 << " and " << str2 << " are anagram" << std::endl;
        else
            std::cout << str1 << " and " << str2 << " are not anagram" << std::endl;
    }
};
int main() {
    Solution::main();
}
