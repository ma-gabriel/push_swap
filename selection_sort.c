/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:58:20 by geymat            #+#    #+#             */
/*   Updated: 2024/01/19 20:30:14 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	empty_storage(int *a, int *stocked, int *second, int swap)
{
	*stocked = -2;
	ft_rr(a, 0);
	while (*second)
	{
		(*second)--;
		ft_rr(a, 0);
	}
	if (swap)
		ft_s(a, 0);
}

static void	pa_ra(t_stack stacks, int *variable, int value)
{
	int	*a;
	int	*b;

	a = stacks.a;
	b = stacks.b;
	*variable = value;
	ft_pa(a, b);
	ft_r(a, 0);
}

static	void	found_max(t_stack stacks, int *swapped,
		int *stocked, int *second)
{
	int	*a;
	int	*b;

	a = stacks.a;
	b = stacks.b;
	ft_pa(a, b);
	if (*swapped)
	{
		*swapped = 0;
		ft_s(a, 0);
		if (*stocked != -1 && a[*a] == *stocked - 1 - (*second >= 1))
			empty_storage(a, stocked, second, 1);
	}
}

static void	rotations(t_stack stacks, int *swapped, int *stocked, int *second)
{
	int	*a;
	int	*b;
	int	index_max;

	a = stacks.a;
	b = stacks.b;
	index_max = ft_index_max(b);
	if (index_max + 1 == *b)
		found_max(stacks, swapped, stocked, second);
	else if (*stocked != 2 && b[*b] == *stocked + 1 + *second)
		pa_ra(stacks, second, *second + 1);
	else if (*stocked == -2 && b[*b] + 6 >= *b)
		pa_ra(stacks, stocked, b[*b]);
	else if (index_max + 1 < *b / 2)
		ft_rr(0, b);
	else
		ft_r(0, b);
}

int	ft_selection_loop(t_stack stacks, int stocked, int second)
{
	int	swapped;
	int	*a;
	int	*b;

	a = stacks.a;
	b = stacks.b;
	swapped = 0;
	while (*b)
	{
		if (stocked != -2 && a[*a] == stocked + 1 + second && !swapped)
			empty_storage(a, &stocked, &second, 0);
		else if (b[*b] + 2 - (stocked != -2) - second == *b
			&& !swapped && stocked != b[*b] + 1)
		{
			ft_pa(a, b);
			swapped = 1;
		}
		else
			rotations(stacks, &swapped, &stocked, &second);
	}
	return (second);
}
