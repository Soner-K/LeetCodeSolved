#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	char			c;
	struct s_stack	*next;
}				t_stack;

void	lst_pop(t_stack **lst)
{
	t_stack	*to_del;

	if (!(*lst))
		return ;
	to_del = *lst;
	(*lst) = (*lst)->next;
	free(to_del);
}

void	lst_push(t_stack **lst, t_stack *new)
{
    if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	(*lst) = new;
}

t_stack	*lstnew(char c)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->c = c;
	new->next = NULL;
	return (new);
}

bool	isValid(char *s)
{
	t_stack	*stack;

    stack = NULL;
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			lst_push(&stack, lstnew(*s));
			s++;
		}
		else
		{
            if (!stack)
                return (false);
			if (stack->c == '(' && *s != ')')
				return (false);
			if (stack->c == '{' && *s != '}')
				return (false);
			if (stack->c == '[' & *s != ']')
				return (false);
			lst_pop(&stack);
			s++;
		}
	}
	if (!stack)
		return (true);
	else
		return (false);
}