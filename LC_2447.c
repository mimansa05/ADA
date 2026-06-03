int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int subarrayGCD(int* nums, int numsSize, int k) {
    
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        
        int currentGCD = 0;

        for (int j = i; j < numsSize; j++) {
            
            currentGCD = gcd(currentGCD, nums[j]);

            if (currentGCD == k) {
                count++;
            }
            else if (currentGCD < k) {
                break;
            }
        }
    }

    return count;
}
