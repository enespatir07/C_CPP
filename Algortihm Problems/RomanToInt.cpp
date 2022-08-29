#include <iostream>
using std::string;
class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            char letter = s[i];
            if (letter == 'I')
                total += 1;
            if (letter == 'V') {
                if (i == 0) {
                    total += 5;
                }
                else if (s[i - 1] == 'I')
                    total += 3;
                else
                    total += 5;
            }
            if (letter == 'X') {
                if (i == 0) {
                    total += 10;
                }
                else if (s[i - 1] == 'I')
                    total += 8;
                else
                    total += 10;
            }
            if (letter == 'L') {
                if (i == 0) {
                    total += 50;
                }
                else if (s[i - 1] == 'X')
                    total += 30;
                else
                    total += 50;
            }
            if (letter == 'C') {
                if (i == 0) {
                    total += 100;
                }
                else if (s[i - 1] == 'X')
                    total += 80;
                else
                    total += 100;
            }
            if (letter == 'D') {
                if (i == 0) {
                    total += 500;
                }
                else if (s[i - 1] == 'C')
                    total += 300;
                else
                    total += 500;
            }
            if (letter == 'M') {
                if (i == 0) {
                    total += 1000;
                }
                else if (s[i - 1] == 'C')
                    total += 800;
                else
                    total += 1000;
            }
        }
        return total;
    }
};
