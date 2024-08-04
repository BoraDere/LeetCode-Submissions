class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'I' && i+1 < s.size() && s[i+1] == 'V') {
                res += 4;
                i++;
                continue;
            }
            else if (c == 'I' && i+1 < s.size() && s[i+1] == 'X') {
                res += 9;
                i++;
                continue;
            }
            else if (c == 'X' && i+1 < s.size() && s[i+1] == 'L') {
                res += 40;
                i++;
                continue;
            }
            else if (c == 'X' && i+1 < s.size() && s[i+1] == 'C') {
                res += 90;
                i++;
                continue;
            }
            else if (c == 'C' && i+1 < s.size() && s[i+1] == 'D') {
                res += 400;
                i++;
                continue;
            }
            else if (c == 'C' && i+1 < s.size() && s[i+1] == 'M') {
                res += 900;
                i++;
                continue;
            }
            else {
                res += table[c];
            }
        }
        return res;
    }
};