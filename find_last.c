/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:34:20 by marvin            #+#    #+#             */
/*   Updated: 2024/07/16 14:34:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	t_stack	*last;

	while (stack->next)
	{
		stack = stack->next;
	}
	last = stack;
	return (last);
}