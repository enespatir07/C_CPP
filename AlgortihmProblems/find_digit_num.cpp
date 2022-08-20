#include <iostream>

int fun(int num) {
    int res = 0;
    while (num != 0) {
        num = num / 10;
        res += 1;
    }
    return res;
}
int main() {
    int input;
    while (true) {
        std::cout << "Enter a number to learn its number of digits: ";
        std::cin >> input;
        if (input == 0) {
            std::cout << "Program terminated";
            break;
        }
        std::cout <<"Number of digits of " <<input<<" is: "<<fun(input)<<std::endl;
    }
}
