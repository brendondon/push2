/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:38:14 by marvin            #+#    #+#             */
/*   Updated: 2024/07/16 09:38:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = NULL;
	if (*dst)
		{
			tmp->next = *dst;
			tmp->next->prev = tmp;
			*dst = tmp;
			return ;
		}
	*dst = tmp;
	tmp->prev = NULL;
}

void	pa(t_stack **a, t_stack **b, int trigger)
{
	push(b, a);
	if (trigger == 1)
		write (1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int trigger)
{
	push(a, b);
	if (trigger == 1)
		write (1, "pb\n", 3);
}