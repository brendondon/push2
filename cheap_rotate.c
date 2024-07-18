/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 00:21:05 by marvin            #+#    #+#             */
/*   Updated: 2024/07/17 00:21:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_2(t_stack **stack_a, t_stack **stack_b, t_stack *cheap_node)
{
	while (*stack_a != cheap_node && *stack_b != cheap_node->target)
		rr(stack_a, stack_b, 1);
	while (*stack_a != cheap_node)
		ra(stack_a, 1);
	while (*stack_b != cheap_node->target)
		rb(stack_b, 1);
}

void	r_rot_2(t_stack **stack_a, t_stack **stack_b, t_stack *cheap_node)
{
	while (*stack_a != cheap_node && *stack_b != cheap_node->target)
		rrr(stack_a, stack_b, 1);
	while (*stack_a != cheap_node)
		rra(stack_a, 1);
	while (*stack_b != cheap_node->target)
		rrb(stack_b, 1);
}

void	ra_rrb(t_stack **stack_a, t_stack **stack_b, t_stack *cheap_node)
{
	while (*stack_a != cheap_node)
		ra(stack_a, 1);
	while (*stack_b != cheap_node->target)
		rrb(stack_b, 1);
}

void	rra_rb(t_stack **stack_a, t_stack **stack_b, t_stack *cheap_node)
{
	while (*stack_a != cheap_node)
		rra(stack_a, 1);
	while (*stack_b != cheap_node->target)
		rb(stack_b, 1);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap_node;

	cheap_node = set_cheapest(stack_a);
	if ((cheap_node->first_half) && (cheap_node->target->first_half))
		rotate_2(stack_a, stack_b, cheap_node);
	else if (!(cheap_node->first_half)
		&& !(cheap_node->target->first_half))
		r_rot_2(stack_a, stack_b, cheap_node);
	else if (cheap_node->first_half && !(cheap_node->target->first_half))
		ra_rrb(stack_a, stack_b, cheap_node);
	else 
		rra_rb(stack_a, stack_b, cheap_node);
}