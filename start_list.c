/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:56:26 by marvin            #+#    #+#             */
/*   Updated: 2024/07/14 19:56:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*add_node(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->data = nb;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void start_list(t_stack **stack, char **buffer)
{
	int		i;
	t_stack	*last_node;
	t_stack	*tmp;

	i = 0;
	while (buffer[i])
	{
		last_node = add_node(ft_atoil(buffer[i++]));
		if(*stack == NULL)
			*stack = last_node;
		else
		{
			tmp = *stack;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = last_node;
			last_node->prev = tmp;
		}
	}
}