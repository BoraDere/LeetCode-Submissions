/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        std::vector<int> values;

        while (head) {
            values.push_back(head->val);
            head = head->next;
        }
        
        return build(values, 0, values.size() - 1);
    }
private:
    TreeNode* build(vector<int>& values, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(values[mid]);

        node->left = build(values, start, mid - 1);
        node->right = build(values, mid + 1, end);

        return node;
    }
};