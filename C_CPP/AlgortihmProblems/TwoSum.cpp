#include <iostream>

class Solution {
public:
    static void Main() {
        int n, target;
        std::cout << "How many numbers you want to store: ";
        std::cin >> n;
        int arr[n];
        int *x = new int(2);
        for (int i = 0; i < n; i++) {
            std::cout << "Enter the number " << (i + 1) << ": ";
            std::cin >> arr[i];
        }
        std::cout << "Enter the target number such that two numbers of array adds up to it: ";
        std::cin >> target;
        x = TwoSum(arr, target, n, x);
        std::cout << "[" << x[0] << ", " << x[1] << "]";
    }

private:
    static int *TwoSum(int *nums, int target, int n, int *x) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    x[0] = i;
                    x[1] = j;
                    break;
                }
            }
        }
        return x;
    }
};

int main() {
    Solution::Main();
}
