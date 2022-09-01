/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Returning the running sum of nums.
*/

class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        vector<int> arr;
        int s = 0;
        for (int i = 0;i<nums.size();i++){
            s += nums[i];
            arr.push_back(s);
        }
        return arr;
    }
};
