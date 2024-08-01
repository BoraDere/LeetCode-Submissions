struct Node {
    Node* child[26];
    bool isLast;
    int childCount;
    Node() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        isLast = false;
        childCount = 0;
    }
};

class Trie {
    private:
        Node* root;
    public:
        Trie() {
            root = new Node();
        }
        void insert(std::string& key) {
            Node* curr = root;
            for (int i = 0; i < key.length(); i++) {
                int index = key[i] - 'a';
                if (curr->child[index] == NULL) {
                    curr->child[index] = new Node();
                    curr->childCount++;
                }
                curr = curr->child[index];
            }
            curr->isLast = true;
        }
        void findPrefix(string& key, string& ans) {
            Node* curr = root;
            for (int i = 0; i < key.size(); i++) {
                int index = key[i] - 'a';
                if (curr->childCount != 1 || curr->isLast) {
                    break;
                }
                curr = curr->child[index];
                ans += key[i];
                
            }
        }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie trie;
        for (string str : strs) {
            trie.insert(str);
        }

        string key = strs[0];
        string ans = "";
        
        trie.findPrefix(key, ans);
        if(ans.size()==0){
            return "";
        }
        return ans;
    }
};