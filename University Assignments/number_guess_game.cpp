#include <iostream>
#include <time.h>
int main() {
    int input, rand_number, lives = 5;
    srand(time(0));
    rand_number = rand() % 10 + 1;
    while (lives > 0) {
        std::cout << "Enter a number (1-10): ";
        std::cin >> input;
        if (rand_number == input) {
            std::cout << "You won" << std::endl;
            return 0;
        } else if (input < rand_number)
            std::cout << input << " is smaller" << std::endl;
        else
            std::cout << input << " is greater" << std::endl;
        lives--;
        if (lives != 0)
            std::cout << "Remaining lives: " << lives << std::endl;
    }
    std::cout << "you lost" << std::endl;
}
