/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:41 by marvin            #+#    #+#             */
/*   Updated: 2024/07/16 14:19:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = find_last(*stack);
	tmp->prev->next = NULL;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}

void	rra(t_stack **a, int trigger)
{
	r_rotate(a);
	if (trigger == 1)
		write (1, "rra\n", 4);
}

void	rrb(t_stack **b, int trigger)
{
	r_rotate(b);
	if (trigger == 1)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int trigger)
{
	r_rotate(a);
	r_rotate(b);
	if (trigger == 1)
		write (1, "rrr\n", 4);
}