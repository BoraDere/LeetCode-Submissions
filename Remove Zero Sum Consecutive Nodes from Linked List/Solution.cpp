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
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {        
        ListNode* dum = new ListNode(0);
        dum->next = head;
        int sum = 0;
        std::unordered_map<int, ListNode*> sums;
        sums[0] = dum;
        ListNode* current = head;

        while (current) {
            sum += current->val;

            if (sums.find(sum) != sums.end()) {
                ListNode* toDelete = sums[sum]->next;
                int tempSum = sum + toDelete->val;

                while (toDelete != current) {
                    sums.erase(tempSum);
                    toDelete = toDelete->next;
                    tempSum += toDelete->val;
                }

                sums[sum]->next = current->next;
            }
            else {
                sums[sum] = current;
            }
            
            current = current->next;
        }

        return dum->next;
    }
};