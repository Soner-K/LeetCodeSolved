/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode	*mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
	struct ListNode	*head;
	struct ListNode	*tail;

	if (!list1 && list2)
		return (list2);
	else if (!list2 && list1)
		return (list1);
    else if (!list1 && !list2)
        return (NULL);
	if (list1->val <= list2->val)
	{
		head = list1;
		list1 = list1->next;
	}
	else
	{
		head = list2;
		list2 = list2->next;
	}
	tail = head;
	while (list1 && list2)
	{
		if (list1->val <= list2->val)
		{
			tail->next = list1;
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			list2 = list2->next;
		}
		tail = tail->next;
	}
	if (list1)
		tail->next = list1;
	else
		tail->next = list2;
	return (head);
}