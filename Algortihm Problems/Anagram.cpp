#include <iostream>
using std::string;

bool isAnagram(string s, string t) {
    int flag = 0;
    if (s.length() != t.length()) // check if lengths match
        return false;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < t.length(); j++) {
            if (s[i] == t[j]) {
                t.erase(j, 1); // matched chars in string t will be erased
                flag++;
                break;
            }
        }
    }
    return flag == s.length();
}
int main() {}
