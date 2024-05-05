/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode	*deleteDuplicates(struct ListNode *head)
{
	short int		curr;
	struct ListNode	*new;
	struct ListNode	*first;

    if (!head)
        return (NULL);
	new = head;
	first = new;
	curr = head->val;
	while (head)
	{
		if (head->val != curr)
		{
			curr = head->val;
			new->next = head;			
			new = new->next;
		}
		head = head->next;
	}
	new->next = NULL;
	return (first);
}