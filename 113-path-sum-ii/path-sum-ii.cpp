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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int >temp;
        vector<vector<int>> ans;

        search(root, targetSum, temp, ans);
        return ans;
    }

private:
    void search(TreeNode* root, int targetSum, vector<int> temp, vector<vector<int>>& ans) {
        if (!root) {
            return;
        }

        temp.push_back(root->val);

        if (!root->left && !root->right && targetSum - root->val == 0) {
            ans.push_back(temp);
        }

        search(root->left, targetSum - root->val, temp, ans);
        search(root->right, targetSum - root->val, temp, ans);
    }
};