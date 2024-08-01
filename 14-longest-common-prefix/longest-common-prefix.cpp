class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string minStr = "";
        int minLen = 201;

        for (std::string str : strs) {
            if (str.length() < minLen) {
                minLen = str.length();
                minStr = str;
            }
        }

        for (std::string str : strs) {
            if (str == minStr) {
                ;
            }
            else {
                for (int i = 0; i < minLen; i++) {
                    if (str[i] != minStr[i]) {
                        minStr = minStr.substr(0, i);
                        minLen = i;
                        break;
                    }
                }
            }
            
        }

        return minStr;
        
    }
};