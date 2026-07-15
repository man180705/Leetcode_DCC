class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // 1+3+5+7 == 2+4+6+8 == 2(1+2+3+4)-4 == 2*n*(n+1)/2 -n ==n*(n+1) -n;
        int oddSum=n*(n+1)-n;
        int evenSum=n*(n+1);
        return gcd(oddSum,evenSum);
    }
};