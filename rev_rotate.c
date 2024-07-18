/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <breda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:41 by marvin            #+#    #+#             */
/*   Updated: 2024/07/18 22:09:11 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = find_last(*stack);
	tmp->prev->next = NULL;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
	(*stack)->next->prev = tmp;
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