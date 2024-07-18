/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <breda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 00:47:35 by marvin            #+#    #+#             */
/*   Updated: 2024/07/18 20:48:37 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sfree(t_stack **head)
{
	t_stack	*to_free;
	t_stack	*tmp;

	if (!head)
		return ;
	to_free = *head;
	while (to_free)
	{
		tmp = to_free->next;
		free(to_free);
		to_free = tmp;
	}
	*head = NULL;
}


void	min_on_top(t_stack **stack_a)
{
	t_stack	*min;

	min = find_min(*stack_a);
	get_index_med(stack_a);
	while (*stack_a != min)
	{
		if (min->first_half)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

void	max_on_top(t_stack **stack)
{
	t_stack		*big;

	big = find_big(*stack);
	while (*stack != big)
	{
		if (big->first_half)
			rb(stack, 1);
		else
			rrb(stack, 1);
	}
}

t_stack	*find_min(t_stack *stack)
{
	int		i;
	t_stack	*min;

	i = INT_MAX;
	while (stack)
	{
		if (stack->data < i)
		{
			i = stack->data;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

