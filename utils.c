/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:16:11 by geymat            #+#    #+#             */
/*   Updated: 2024/01/09 20:48:06 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_pa(int *a, int *b)
{
	if (!a || !b || !b[0])
		return ;
	a[a[0] + 1] = b[b[0]];
	(a[0])++;
	(b[0])--;
	write(1, "pa\n", 3);
}

void	ft_pb(int *a, int *b)
{
	if (!a || !b || !a[0])
		return ;
	b[b[0] + 1] = a[a[0]];
	(b[0])++;
	(a[0])--;
	write(1, "pb\n", 3);
}

void	ft_r(int *a, int *b)
{
	int	temp;
	int	i;

	i = 0;
	while (a && ++i < a[0])
	{
		temp = a[a[0] - i + 1];
		a[a[0] - i + 1] = a[a[0] - i];
		a[a[0] - i] = temp;
	}
	i = 0;
	while (b && ++i < b[0])
	{
		temp = b[b[0] - i + 1];
		b[b[0] - i + 1] = b[b[0] - i];
		b[b[0] - i] = temp;
	}
	if ((a != NULL) + (b != NULL) * 2 == 1)
		write(1, "ra\n", 3);
	if ((a != NULL) + (b != NULL) * 2 == 2)
		write(1, "rb\n", 3);
	if ((a != NULL) + (b != NULL) * 2 == 3)
		write(1, "rr\n", 3);
}

void	ft_s(int *a, int *b)
{
	int	temp;

	if (a && a[0] && a[0] - 1)
	{
		temp = a[a[0]];
		a[a[0]] = a[a[0] - 1];
		a[a[0] - 1] = temp;
	}
	if (b && b[0] && b[0] - 1)
	{
		temp = b[b[0]];
		b[b[0]] = b[b[0] -1];
		b[b[0] - 1] = temp;
	}
	if ((a != NULL) + (b != NULL) * 2 == 1)
		write(1, "sa\n", 3);
	if ((a != NULL) + (b != NULL) * 2 == 2)
		write(1, "sb\n", 3);
	if ((a != NULL) + (b != NULL) * 2 == 3)
		write(1, "ss\n", 3);
}

void	ft_rr(int *a, int *b)
{
	int	temp;
	int	i;

	i = 1;
	while (a && ++i < a[0] + 1)
	{
		temp = a[i];
		a[i] = a[i - 1];
		a[i - 1] = temp;
	}
	i = 1;
	while (b && ++i < b[0] + 1)
	{
		temp = b[i];
		b[i] = b[i - 1];
		b[i - 1] = temp;
	}
	if ((a != NULL) + (b != NULL) * 2 == 1)
		write(1, "rra\n", 4);
	if ((a != NULL) + (b != NULL) * 2 == 2)
		write(1, "rrb\n", 4);
	if ((a != NULL) + (b != NULL) * 2 == 3)
		write(1, "rrr\n", 4);
}
