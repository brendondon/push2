/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 23:01:30 by marvin            #+#    #+#             */
/*   Updated: 2024/06/04 23:01:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

long long	ft_atoil(const char *str)
{
	int			i;
	long long	result;
	long long	signal;

	signal = 1;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			signal = signal * -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * signal);
}

static	int	check_digit(char *number)
{
	int	i;

	i = 0;
	if (number[0] == '-')
	{
		i++;
		if (!number[1])
			return (0);
	}
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

static	int	check_repeat(int num, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (0);
		i++;
	}
	return (1);
}

void	str_free(char ***numbers)
{
	int	i;

	i = 0;
	while ((*numbers)[i])
	{
		free((*numbers)[i]);
		(*numbers)[i] = NULL;
		i++;
	}
	free(*numbers);
	*numbers = NULL;
}

void	check_input(int ac, char **av)
{
	int i;
	long long num;
	
	if(ac == 2)
		av = ft_split(av[1], ' ');
	else
		av = &av[1];
	i = 0;

	while (av[i])
	{
		num = ft_atoil(av[i]);
		if(!av[i][0] || !check_digit(av[i]) || (num > 2147483647 || num < -2147483648) || !check_repeat(num, &av[i]))
		{
			if(ac == 2)
				str_free(&av);
			write (1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	if(ac == 2)
		str_free(&av);
}