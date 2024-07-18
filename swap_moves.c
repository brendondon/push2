/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:05:47 by marvin            #+#    #+#             */
/*   Updated: 2024/07/15 16:05:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	(*stack) = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack **a, int trigger)
{
	swap(a);
	if (trigger == 1)
		write (1, "sa\n", 3);
}

void	sb(t_stack **b, int trigger)
{
	swap(b);
	if (trigger == 1)
		write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int trigger)
{
	swap(a);
	swap(b);
	if (trigger == 1)
		write (1, "ss\n", 3);
}