/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 02:27:11 by geymat            #+#    #+#             */
/*   Updated: 2024/01/19 18:14:16 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort(int *a, int *b);
static void	ft_r_quicksort(int *a, int *b, int start, int end);
static void	ft_quicksort(int *a, int *b, int start, int end);
static void	ft_selection_sort(int *a, int *b);

void	ft_sort(int *a, int *b)
{
	const int	end = *a;
	const int	start = 0;

	while (*a > (end - start) / 2 + 1)
	{
		if (a[*a] <= (start + end) / 2)
			ft_pb(a, b);
		else
			ft_r(a, 0);
	}
	ft_r_quicksort(a, b, start, end / 2);
	ft_quicksort(a, b, start, end);
	ft_selection_sort(a, b);
}

static void	ft_quicksort(int *a, int *b, int start, int end)
{
	while (*a > (end - start) / 2 + 1)
	{
		if (a[*a] <= (start + end) / 2)
			ft_pb(a, b);
		else
			ft_r(a, 0);
	}
	if (*a == 1)
		ft_pb(a, b);
	if (*a)
		ft_quicksort(a, b, (start + end) / 2, end);
}

static void	ft_r_quicksort(int *a, int *b, int start, int end)
{
	while (*b > (end - start) / 2)
	{
		if (b[*b] >= (start + end) / 2)
			ft_pa(a, b);
		else
			ft_r(0, b);
	}
	if (*b == 1)
		ft_pa(a, b);
	if (*b)
		ft_r_quicksort(a, b, start, end / 2);
}

static void	ft_selection_sort(int *a, int *b)
{
	int		stocked;
	int		second;
	t_stack	stacks;
	int		check;

	stacks.a = a;
	stacks.b = b;
	second = 0;
	stocked = -2;
	check = ft_selection_loop(stacks, stocked, second);
	while (!ft_sorted(a) && check--)
		ft_rr(a, 0);
}
