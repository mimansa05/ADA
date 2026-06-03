int findTargetSumWays(int* nums, int numsSize, int target) {

    int totalSum = 0;

    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    // impossible case
    if ((target + totalSum) % 2 != 0 || abs(target) > totalSum) {
        return 0;
    }

    int subsetSum = (target + totalSum) / 2;

    int dp[subsetSum + 1];

    for (int i = 0; i <= subsetSum; i++) {
        dp[i] = 0;
    }

    dp[0] = 1;

    for (int i = 0; i < numsSize; i++) {

        for (int j = subsetSum; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }

    return dp[subsetSum];
}
