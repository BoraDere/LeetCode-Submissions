/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void search(TreeNode* root, int level, vector<vector<int>>& ans) {
        if (root !=  nullptr) {
            if (level == ans.size()) {
                vector<int> newVec;
                ans.push_back(newVec);
            }
            search(root->left, level+1, ans);
            ans[level].push_back(root->val);
            search(root->right, level+1, ans);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        search(root, 0, ans);
        return ans;
    }
};