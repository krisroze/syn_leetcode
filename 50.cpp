// leetcode.com/problems/powx-n/
class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return solvePow(x, N);
    }
private:
    double solvePow(double x, long n) {
        if (n == 0) return 1;
        double half = solvePow(x, n / 2);
        double result = half * half;
        if (n % 2 == 1) result *= x;
        return result;
    }
};