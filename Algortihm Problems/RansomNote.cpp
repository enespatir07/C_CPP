/*
*Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
*Each letter in magazine can only be used once in ransomNote.
*/
class Solution {
public:
    bool check(char letter, string &word) {
        for (int i = 0; i < word.length(); i++) {
            if (letter == word.at(i)) {
                word[i] = '-';
                return true;
            }
        }
        return false;
    }
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length())
            return false;
        for (int i = 0; i < ransomNote.length(); i++) {
            char r = ransomNote.at(i);
            if (r != '-') {
                if (check(r, magazine) == false)
                    return false;
            }
        }
        return true;
    }
};
