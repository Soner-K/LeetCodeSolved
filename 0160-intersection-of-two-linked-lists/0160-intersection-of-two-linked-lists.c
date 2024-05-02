/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #include <stdio.h>
 typedef struct ListNode node;
__uint16_t	lstsize(node *head)
{
	__uint16_t	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

struct ListNode	*getIntersectionNode(struct ListNode *headA,
		struct ListNode *headB)
{
	__uint16_t	size_a;
	__uint16_t	size_b;

	size_a = lstsize(headA);
	size_b = lstsize(headB);
	while (size_a > size_b)
	{
		headA = headA->next;
		size_a--;
	}
	while (size_b > size_a)
	{
		headB = headB->next;
		size_b--;
	}
	while (headA && headB)
	{
		if (headA == headB)
			return (headA);
		headA = headA->next;
		headB = headB->next;
	}
	return (NULL);
}