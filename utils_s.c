/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:16:11 by geymat            #+#    #+#             */
/*   Updated: 2024/01/13 06:59:51 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_pa_s(int *a, int *b, int silence)
{
	if (!a || !b || !b[0])
		return (0);
	a[a[0] + 1] = b[b[0]];
	(a[0])++;
	(b[0])--;
	if (silence)
		return (1);
	write(1, "pa\n", 3);
	return (0);
}

int	ft_pb_s(int *a, int *b, int silence)
{
	if (!a || !b || !a[0])
		return (0);
	b[b[0] + 1] = a[a[0]];
	(b[0])++;
	(a[0])--;
	if (silence)
		return (1);
	write(1, "pb\n", 3);
	return (1);
}

void	ft_r_s(int *a, int *b, int silence)
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
	if ((a != NULL) + (b != NULL) * 2 == 1 && !silence)
		write(1, "ra\n", 3);
	if ((a != NULL) + (b != NULL) * 2 == 2 && !silence)
		write(1, "rb\n", 3);
	if ((a != NULL) + (b != NULL) * 2 == 3 && !silence)
		write(1, "rr\n", 3);
}

void	ft_s_s(int *a, int *b, int silence)
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
	if ((a != NULL) + (b != NULL) * 2 == 1 && !silence)
		write(1, "sa\n", 3);
	if ((a != NULL) + (b != NULL) * 2 == 2 && !silence)
		write(1, "sb\n", 3);
	if ((a != NULL) + (b != NULL) * 2 == 3 && !silence)
		write(1, "ss\n", 3);
}

void	ft_rr_s(int *a, int *b, int silence)
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
	if ((a != NULL) + (b != NULL) * 2 == 1 && !silence)
		write(1, "rra\n", 4);
	if ((a != NULL) + (b != NULL) * 2 == 2 && !silence)
		write(1, "rrb\n", 4);
	if ((a != NULL) + (b != NULL) * 2 == 3 && !silence)
		write(1, "rrr\n", 4);
}
