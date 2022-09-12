#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int> &nums) {
        int l = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[l] = nums[i];
                l++;
            }
        }
        return l;
    }
};
