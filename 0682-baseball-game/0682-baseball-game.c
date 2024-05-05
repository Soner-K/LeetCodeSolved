/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calPoints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:05:01 by sokaraku          #+#    #+#             */
/*   Updated: 2024/04/29 14:13:31 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				score;
	struct s_stack	*next;
}					t_stack;

short int	tiny_atoi(char *s, char is_negative)
{
	short int	res;

	res = 0;
	if (*s == '-')
		s++;
	while (*s)
	{
		res *= 10;
		res += (*s - '0');
		s++;
	}
	if (is_negative)
		return (res * -1);
	return (res);
}

t_stack	*lstnew(int score)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->score = score;
	return (new);
}
 
int	calPoints(char **operations, int operationsSize)
{
	t_stack	*stack;
    t_stack *tmp;

	int		res;

	stack = NULL;
	res = 0;
	while (operationsSize--)
	{
		if (*operations[0] == '+')
		{
			res = stack->score + stack->next->score;
            tmp = stack;
            stack = lstnew(res);
            stack->next = tmp;
		}
		else if (*operations[0] == 'D')
		{
			res = stack->score * 2;
			tmp = stack;
            stack = lstnew(res);
            stack->next = tmp;
		}
		else if (*operations[0] == 'C')
			stack = stack->next;
		else
		{
			res = tiny_atoi(*operations, *operations[0] == '-');
			tmp = stack;
            stack = lstnew(res);
            stack->next = tmp;
		}
		operations++;
	}
	if (!stack)
		return (0);
	res = 0;
	while (stack)
	{
		res += stack->score;
		stack = stack->next;
	}
	return (res);
}
