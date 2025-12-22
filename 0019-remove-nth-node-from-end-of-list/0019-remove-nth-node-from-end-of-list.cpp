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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // 1. Create dummy node
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* current = head;
        ListNode* fast = head;

        // 2. Move fast pointer n steps ahead
        for (int i = 1; i <= n; i++) {
            if (fast != NULL)
                fast = fast->next;
        }

        // 3. Move all pointers until fast reaches NULL
        while (fast != NULL) {
            prev = current;
            current = current->next;
            fast = fast->next;
        }

        // 4. Delete current node
        if (current != NULL) {
            prev->next = current->next;
            delete current;
        }

        return dummy->next; // updated head
    }
};