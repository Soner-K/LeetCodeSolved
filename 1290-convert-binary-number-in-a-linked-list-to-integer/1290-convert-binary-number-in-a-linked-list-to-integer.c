__uint8_t	lstsize(struct ListNode *head)
{
	__uint8_t	size;

	size = 0;
	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}

int	getDecimalValue(struct ListNode *head)
{
	int			result;
	__uint8_t	size;

	result = 0;
	size = lstsize(head);
	while (head)
	{
		size--;
		result = result + (head->val << size);
		head = head->next;
	}
	return (result);
}