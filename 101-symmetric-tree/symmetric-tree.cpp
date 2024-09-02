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
    bool search(TreeNode* left, TreeNode* right) {
        if ((!left && right) || (left && !right)) {
            return false;
        }

        if (!left && !right) {
            return true;
        }

        if (left->val != right->val) {
            return false;
        }

        search(left->left, right->right);
        search(left->right, right->left);

        return search(left->left, right->right) && search(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return search(root->left, root->right);
    }
};