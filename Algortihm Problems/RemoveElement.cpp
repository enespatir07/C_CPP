#include <iostream>
#include <vector>
using namespace ::std;

int removeElement(vector<int> &nums, int val) {
    vector<int>::iterator itr = nums.begin();
    while (itr != nums.end()) {
        if (*itr == val)
            nums.erase(itr);
        else
            itr++;
    }
    return nums.size();
}
int main() {
    vector<int> nums;
    int n, val, x;
    cout << "How many numbers you want to store: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ":";
        cin >> x;
        nums.push_back(x);
    }
    cout << "Enter the number you want to remove: ";
    cin >> val;
    cout << "Original: ";
    for (auto itr : nums)
        cout << itr << " ";
    cout << "\nFinal: ";
    removeElement(nums, val);
    for (auto itr : nums)
        cout << itr << " ";
}
