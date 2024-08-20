class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), sortcol);

        for (auto interval : intervals) {
            if (res.empty()) {
                res.push_back(interval);
            }
            else if (interval[0] <= res[res.size() - 1][1]) {
                res[res.size() - 1][1] = max(interval[1], res[res.size() - 1][1]);
            }
            else {
                res.push_back(interval);
            }
        }

        return res;
    }
};