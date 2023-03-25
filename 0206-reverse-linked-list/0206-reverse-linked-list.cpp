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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        
        ListNode* prv = NULL;
        while(head->next) 
        {
            ListNode* nxt = head->next;
            head->next = prv;
            prv = head;
            head = nxt;
        }
        head->next = prv;
        return head;
    }
};
