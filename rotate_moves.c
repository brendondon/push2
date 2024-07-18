/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:24:06 by marvin            #+#    #+#             */
/*   Updated: 2024/07/16 13:24:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = find_last(*stack);
	tmp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next->next = NULL;
	tmp->next->prev = tmp;
}

void	ra(t_stack **a, int trigger)
{
	rotate(a);
	if (trigger == 1)
		write (1, "ra\n", 3);
}

void	rb(t_stack **b, int trigger)
{
	rotate(b);
	if (trigger == 1)
		write (1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int trigger)
{
	rotate(a);
	rotate(b);
	if (trigger == 1)
		write (1, "rr\n", 3);
}
