
int gcdOfOddEvenSums(int n) {
    
    int oddSum = n * n;
    int evenSum = n * (n + 1);

    // find gcd using Euclidean algorithm
    while (evenSum != 0) {
        int temp = evenSum;
        evenSum = oddSum % evenSum;
        oddSum = temp;
    }

    return oddSum;
}
