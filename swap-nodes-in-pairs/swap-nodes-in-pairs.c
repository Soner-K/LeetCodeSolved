/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;

struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next)
        return (head);
    ListNode    *tmp;
    tmp = head->next;
    head->next = swapPairs(tmp->next);
    tmp->next = head;
    return (tmp);
}