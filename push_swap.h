/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:01:24 by marvin            #+#    #+#             */
/*   Updated: 2024/06/04 19:01:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "Libft/libft.h"
# include <limits.h>


typedef struct	s_stack
{
	int data;
	int index;
	int	first_half;
	int	cost;
	int cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;

} t_stack;

void 	check_input(int ac, char **av);
void 	start_list(t_stack **first_node, char **buffer);
void	check_input(int ac, char **av);
void	str_free(char ***numbers);
void	push_swap(t_stack **stack_a);
int 	check_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
void	sort_three(t_stack **stack);
void	ra(t_stack **a, int trigger);
void	rb(t_stack **b, int trigger);
void	rr(t_stack **a, t_stack **b, int trigger);
void	rra(t_stack **a, int trigger);
void	rrb(t_stack **b, int trigger);
void	rrr(t_stack **a, t_stack **b, int trigger);
void	sa(t_stack **a, int trigger);
void	sb(t_stack **b, int trigger);
void	ss(t_stack **a, t_stack **b, int trigger);
void	pa(t_stack **a, t_stack **b, int trigger);
void	pb(t_stack **a, t_stack **b, int trigger);
t_stack	*find_last(t_stack *stack);
t_stack	*find_big(t_stack *stack);
void	start_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_2(t_stack **stack_a, t_stack **stack_b, t_stack *cheap_node);
void	r_rot_2(t_stack **stack_a, t_stack **stack_b, t_stack *cheap_node);
void	ra_rrb(t_stack **stack_a, t_stack **stack_b, t_stack *cheap_node);
void	rra_rb(t_stack **stack_a, t_stack **stack_b, t_stack *cheap_node);
void	push_to_b(t_stack **stack_a, t_stack **stack_b);
t_stack	*set_cheapest(t_stack **stack);
void	push_to_b(t_stack **stack_a, t_stack **stack_b);
int		stack_is_sorted(t_stack *stack);
void	push_to_a(t_stack **stack_a, t_stack **stack_b);
void	get_target_b(t_stack **stack_a, t_stack **stack_b);
void	set_datas_b(t_stack **stack_a, t_stack **stack_b);
void	get_target_b(t_stack **stack_a, t_stack **stack_b);
void	min_on_top(t_stack **stack_a);
void	max_on_top(t_stack **stack);
t_stack	*find_min(t_stack *stack);
void	get_target(t_stack **a, t_stack **b);
void	get_index_med(t_stack **stack);
void	check_decrease_cost(t_stack **stack_a, t_stack **stack_b, t_stack *tmp);
void	set_datas(t_stack **stack_a, t_stack **stack_b);
long long	ft_atoil(const char *str);
void	ft_sfree(t_stack **head);

#endif