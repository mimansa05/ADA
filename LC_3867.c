int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
long long gcdSum(int* nums, int numsSize) {

    int* prefixGcd = (int*)malloc(numsSize * sizeof(int));

    int mx = 0;

    // build prefixGcd array
    for (int i = 0; i < numsSize; i++) {

        if (nums[i] > mx) {
            mx = nums[i];
        }
       prefixGcd[i] = gcd(nums[i], mx);
    }

    qsort(prefixGcd, numsSize, sizeof(int), cmp);
 long long sum = 0;

    int left = 0;
    int right = numsSize - 1;
    while (left < right) {

        sum += gcd(prefixGcd[left], prefixGcd[right]);

        left++;
        right--;
    }

    free(prefixGcd);
    return sum;
}
