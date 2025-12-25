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
    void reorderList(ListNode* head) {

        // Edge cases
        if (!head || !head->next || !head->next->next) return;

        /*--------------------------------------------------
          1. Find middle of the linked list
        --------------------------------------------------*/
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        /*--------------------------------------------------
          2. Reverse second half of the list
             (from slow->next to end)
        --------------------------------------------------*/
        ListNode* curr = slow->next;
        slow->next = nullptr;        // break list into two halves

        ListNode* prev = nullptr;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        /*--------------------------------------------------
          3. Merge both halves alternately
        --------------------------------------------------*/
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};