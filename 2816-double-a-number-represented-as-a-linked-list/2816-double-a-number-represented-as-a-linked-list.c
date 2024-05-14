typedef struct ListNode ListNode;

struct ListNode* doubleIt(struct ListNode* head){
	ListNode	*prev; 
	ListNode	*itr;

	if (head->val > 4)
	{
		prev = malloc(sizeof(ListNode));
		prev->val = 1;
		prev->next = head;
		head = prev;
        	prev = head->next;
        	itr = head->next->next;
	}
	else
	{
	    prev = head;
	    itr = head->next;
	}
	prev->val = (prev->val * 2) % 10;
	if (!itr)
		return (head);
	while (itr)
	{
		itr->val *= 2;
		if (itr->val >= 10)
			prev->val++;
		itr->val %= 10;
		itr = itr->next;
		prev = prev->next;
	}
	return (head);
}        
