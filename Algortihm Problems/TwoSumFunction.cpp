int *TwoSum(int *nums, int target, int n, int *x) {
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

