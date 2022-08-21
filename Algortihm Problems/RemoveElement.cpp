#include <iostream>
#include <vector>
using namespace ::std;

int removeElement(vector<int> &nums, int val) {
    auto itr = nums.begin();//iterator pointing to the beginning of vector
    while (itr != nums.end()) {
        if (*itr == val)
            nums.erase(itr);//erases the target
        else
            itr++;//points to next element
    }
    return nums.size();//returns the new length of vector
}

