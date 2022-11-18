class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }

        for (auto fact : {2, 3, 5}) {
            n = div(n, fact);
        }

        return n == 1;
    }

    int div(int n, int fact) {
        while (n % fact == 0) {
            n /= fact;;
        }
        return n;
    }
};