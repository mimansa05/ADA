int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int countDifferentSubsequenceGCDs(int* nums, int numsSize) {

    int maxNum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxNum) {
            maxNum = nums[i];
        }
    }

    int* exists = (int*)calloc(maxNum + 1, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        exists[nums[i]] = 1;
    }

    int answer = 0;

    for (int x = 1; x <= maxNum; x++) {

        int currentGCD = 0;
       for (int multiple = x; multiple <= maxNum; multiple += x) {

            if (exists[multiple]) {
                currentGCD = gcd(currentGCD, multiple);

                if (currentGCD == x) {
                    answer++;
                    break;
                }
            }
        }
    }

    free(exists);
return answer;
}
