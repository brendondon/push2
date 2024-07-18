/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:40:25 by marvin            #+#    #+#             */
/*   Updated: 2024/07/16 16:40:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	get_index_med(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int		med;

	med = stack_size(*stack);
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		if (med / 2 > i)
			tmp->first_half = 1;
		else
			tmp->first_half = 0;
		tmp = tmp->next;
		i++;
	}
}

void	get_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*cur_b;
	int		cur_match;

	tmp = *stack_a;
	while (tmp)
	{
		cur_match = INT_MIN;
		cur_b = *stack_b;
		while (cur_b)
		{
			if (cur_b->data > cur_match && cur_b->data < tmp->data)
			{
				tmp->target = cur_b;
				cur_match = cur_b->data;
			}
			cur_b = cur_b->next;
		}
		if (cur_match == INT_MIN)
			tmp->target = find_big(*stack_b);
		tmp = tmp->next;
	}
}

void	check_decrease_cost(t_stack **stack_a, t_stack **stack_b, t_stack *tmp)
{
	if (tmp->first_half && tmp->target->first_half)
	{
		if (tmp->index < tmp->target->index)
			tmp->cost -= tmp->index;
		else
			tmp->cost -= tmp->target->index;
	}
	if (!tmp->first_half && !tmp->target->first_half)
	{
		if (stack_size(*stack_a) - tmp->index < stack_size(*stack_b) - tmp->target->index)
			tmp->cost -= stack_size(*stack_a) - tmp->index;
		else
			tmp->cost -= stack_size(*stack_b) - tmp->target->index;
	}
}
	
void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	
	tmp = *stack_a;
	while (tmp)
	{
		if(tmp->first_half)
			tmp->cost = tmp->index;
		if(!tmp->first_half)
			tmp->cost = stack_size(*stack_a) - tmp->index;
		if(tmp->target->first_half)
			tmp->cost += tmp->target->index;
		if(!(tmp->target->first_half))
			tmp->cost += stack_size(*stack_b) - tmp->target->index;
		check_decrease_cost(stack_a, stack_b, tmp);
		tmp = tmp->next;
	}
}

t_stack	*set_cheapest(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*cheap_node;
	int		cur_cheapest;

	tmp = *stack;
	cheap_node = *stack;
	cur_cheapest = INT_MAX;
	while (tmp)
	{
		if (tmp->cost < cur_cheapest)
		{
			cheap_node = tmp;
			cur_cheapest = tmp->cost;
		}
		tmp = tmp->next;
	}
	tmp = *stack;
	cheap_node->cheapest = 1;
	while (tmp)
	{
		if (tmp != cheap_node)
			tmp->cheapest = 0;
		tmp = tmp->next;
	}
	return (cheap_node);
}

void	set_datas(t_stack **stack_a, t_stack **stack_b)
{
	get_index_med(stack_a);
	get_index_med(stack_b);
	get_target(stack_a, stack_b);
	get_cost(stack_a, stack_b);
}

