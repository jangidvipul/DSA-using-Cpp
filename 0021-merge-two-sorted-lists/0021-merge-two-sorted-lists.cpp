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
    // Merge Two Sorted Linked Lists using Dummy Node Pattern

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // 1. Create dummy node
        ListNode* dummy = new ListNode(-1);

        ListNode* prev = dummy;
        ListNode* current1 = list1;
        ListNode* current2 = list2;

        // 2. Traverse both lists
        while (current1 != NULL && current2 != NULL) {

            if (current1->val <= current2->val) {
                prev->next = current1;
                current1 = current1->next;
            } else {
                prev->next = current2;
                current2 = current2->next;
            }

            prev = prev->next; // move prev forward
        }

        // 3. Attach remaining list
        if (current1 != NULL)
            prev->next = current1;
        else
            prev->next = current2;

        return dummy->next; // head of merged list
    }
};