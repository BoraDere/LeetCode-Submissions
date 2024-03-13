class Solution {
    
public:
    int pivotInteger(int n) {
        for (int x = 1; x < n + 1; x++) {
            int sum = 0;

            for (int i = n - x + 1; i < x; i++) {
                sum += i;
            }

            if ((n-x)*(-x) + sum == 0) {
                return x;
            }
        }

        return -1;
    }
};