/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_starts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <breda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:33:24 by marvin            #+#    #+#             */
/*   Updated: 2024/07/18 23:17:27 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	start_b(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b, 1);
	if (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b, 1);
	while (stack_size(*stack_a) > 3)
	{
		set_datas(stack_a, stack_b);
		push_to_b(stack_a, stack_b);
		pb(stack_a, stack_b, 1);
	}
	set_datas(stack_a, stack_b);
	max_on_top(stack_b);
}