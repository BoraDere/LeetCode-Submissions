class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;

        if (charStack.size() % 2 != 0) {
            return false;
        }

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                charStack.push(c);
            }
            else {
                if (charStack.empty() || 
                (c == ')' && charStack.top() != '(') || 
                (c == ']' && charStack.top() != '[') || 
                (c == '}' && charStack.top() != '{')) {
                    return false;
                }
                charStack.pop();
            }
        }

        return charStack.empty();
    }
};