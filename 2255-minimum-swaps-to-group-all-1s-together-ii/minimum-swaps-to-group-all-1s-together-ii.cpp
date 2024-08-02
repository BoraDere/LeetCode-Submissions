#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        int n = nums.size();
        if (sum == 0 || sum == n) return 0; 

        vector<int> extended(nums.begin(), nums.end());
        extended.insert(extended.end(), nums.begin(), nums.end());

        int min_zeros = sum; 
        int current_zeros = 0;

        for (int i = 0; i < sum; ++i) {
            if (extended[i] == 0) current_zeros++;
        }
        min_zeros = current_zeros;

        for (int i = sum; i < 2 * n; ++i) {
            if (extended[i] == 0) current_zeros++;            
            if (extended[i - sum] == 0) current_zeros--;      
            min_zeros = min(min_zeros, current_zeros);        
        }

        return min_zeros;
    }
};
