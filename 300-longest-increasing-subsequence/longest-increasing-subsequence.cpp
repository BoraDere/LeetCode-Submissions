class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int num : nums) {
            if (sub.empty() || sub[sub.size() - 1] < num) {
                sub.push_back(num);
            } 
            else {
                auto it = lower_bound(sub.begin(), sub.end(), num); 
                *it = num; 
            }
        }
        return sub.size();
    }
};