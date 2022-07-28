#include <iostream>
class Solution {
private:
    static bool isperfect(int n) {
        int s = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0)
                s += i;
        }
        return s == n;
    }
public:
    static void main(){
        int n;
        std::cout << "Enter the upper bound to search for perfect numbers: ";
        std::cin >> n;
        std::cout << "Below are all perfect numbers till " << n << std::endl;
        for (int i = 2; i < n; i++) {
            if (isperfect(i))
                std::cout << i << " is a perfect number " << std::endl;
        }
    }
};
int main() {
    Solution::main();
}
