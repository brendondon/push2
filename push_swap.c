/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 02:27:39 by marvin            #+#    #+#             */
/*   Updated: 2024/07/15 02:27:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	stack_is_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}
t_stack	*find_big(t_stack *stack)
{
	t_stack		*big;
	int			i;

	i = INT_MIN;
	big = stack;
	while (stack)
	{
		if (stack->data > i)
		{
			i = stack->data;
			big = stack;
		}
		stack = stack->next;
	}
	return (big);
}

void	sort_three(t_stack **stack)
{
	t_stack	*big;

	big = find_big(*stack);
	if (big == *stack)
		ra(stack, 1);
	else if (big == (*stack)->next)
		rra(stack, 1);
	if (!stack_is_sorted(*stack))
		sa(stack, 1);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int check_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if( stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}


void	push_swap(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (!check_sorted(*stack_a))
	{
		if (stack_size(*stack_a) == 2)
			sa(stack_a, 1);
		if (stack_size(*stack_a) == 3)
			sort_three(stack_a);
		if (stack_size(*stack_a) > 3)
		{
			start_b(stack_a, &stack_b);
			sort_three(stack_a);
		}
		push_to_a(stack_a, &stack_b);
	}
}

	