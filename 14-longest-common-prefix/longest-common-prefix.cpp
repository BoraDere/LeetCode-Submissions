struct Node {
    Node* child[26];
    int childCount;
    bool isLast;
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

        void insert(string& key) {
            Node* curr = root;
            for (int i = 0; i < key.size(); i++) {
                int index = key[i] - 'a';
                if (curr->child[index] == NULL) {
                    curr->child[index] = new Node;
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
                if (curr->isLast || curr->childCount > 1) {
                    break;
                }
                ans += key[i];
                curr = curr->child[index];
            }
        }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        Trie trie;
        for (string str : strs) {
            trie.insert(str);
        }

        string ans = "";
        string key = strs[0];
        trie.findPrefix(key, ans);

        if(ans.size()==0){
            return "";
        }

        return ans;
    }
};