/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:40:30 by geymat            #+#    #+#             */
/*   Updated: 2024/01/31 04:01:17 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(const char *str)
{
	size_t		i;
	int			sign;
	long int	res;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	i--;
	while (str[++i] <= '9' && str[i] >= '0')
	{
		if (res * 10 + (str[i] - '0') < res)
			return (1000000000000);
		res = res * 10 + (str[i] - '0');
	}
	if (!str[i])
		return (res * sign);
	return (10000000000);
}

int	ft_sorted(int *a)
{
	int	i;

	if (!a)
		return (0);
	i = 1;
	while (i < a[0])
	{
		if (a[i] < a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_index_max(int *a)
{
	int	i;
	int	index_max;

	index_max = 1;
	i = 1;
	while (i < *a + 1)
	{
		if (a[i] >= a[index_max])
			index_max = i;
		i++;
	}
	return (index_max - 1);
}

void	ft_pushswap(int *a, int *b)
{
	if (*a <= 8 && !ft_sorted(a))
		ft_sort_backtrack(a, b);
	if (ft_sorted(a))
		return ;
	ft_sort(a, b);
}

int	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i ++;
	return (i);
}
