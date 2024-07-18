/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:11:24 by marvin            #+#    #+#             */
/*   Updated: 2024/06/04 18:11:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	*stack_a;


	stack_a = NULL;
	if (ac == 1 || (!av[1][0] && ac == 2))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	check_input(ac, av);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av = av + 1;
	start_list(&stack_a, av);
	push_swap(&stack_a);
	if (ac == 2)
		str_free(&av);
	ft_sfree(&stack_a);
	
	return (0);
}