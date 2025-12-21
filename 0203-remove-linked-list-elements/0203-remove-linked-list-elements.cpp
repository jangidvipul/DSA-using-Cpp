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
    ListNode* removeElements(ListNode* head, int val) {
        // create a 'dummy' node and link it to 'head' of L.L.
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // use two ptrs- 'prev' and 'current' to update links in L.L.
        ListNode* prev = dummy;
        ListNode* current = head;

        while(current){
            // IF this current Node's value we have to delete-
            if(current->val == val){
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else{
                prev = current;
                current = current->next;
            }
        }

        return dummy->next; // updated 'head'
    }
};