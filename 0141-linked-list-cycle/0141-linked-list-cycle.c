#include <stdbool.h>

#define CAPACITY 200001

char	is_here(struct ListNode *ptr)
{
	static short int tab[CAPACITY];

	if (tab[(unsigned long)ptr % CAPACITY]!= 0)
		return (true);
	tab[(unsigned long)ptr % CAPACITY] = (unsigned long)ptr % CAPACITY;
	return (false);
}

bool	hasCycle(struct ListNode *head)
{
	while (head)
	{
		if (is_here(head))
			return (true);
		head = head->next;
	}
	return (false);
} 