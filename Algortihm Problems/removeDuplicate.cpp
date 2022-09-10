#include <iostream>
#include <vector>
using namespace std;

vector<int> fun(vector<int> &arr) {
    vector<int> result;
    result.push_back(arr[0]);
    int last = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != result[last]) {
            result.push_back(arr[i]);
            last++;
        }
    }
    return result;
}
