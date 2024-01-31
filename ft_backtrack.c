/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 06:40:27 by geymat            #+#    #+#             */
/*   Updated: 2024/01/13 13:19:00 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static t_methode	*back_r(int *a, int *b, int count);
static t_methode	*back_rr(int *a, int *b, int count);
t_methode			*ft_back_p(int *a, int *b, int count);
static t_methode	*back_s(int *a, int *b, int count);
t_methode			*max_methode(t_methode *one, t_methode *two,
						t_methode *three, t_methode *four);

t_methode	*ft_back_p(int *a, int *b, int count)
{
	t_methode	*pa;
	int			worked;

	if (!count || (ft_sorted(a) && !(*b)))
		return (methode_newval(a, count));
	worked = ft_pa_s(a, b, 1);
	pa = pa_back_p(a, b, count - 1);
	if (!pa)
		return (NULL);
	pa->value *= worked;
	pa->function_id = 0;
	if (worked)
		ft_pb_s(a, b, 1);
	return (max_methode(pa, back_r(a, b, count), 0, 0));
}

static t_methode	*back_r(int *a, int *b, int count)
{
	t_methode	*ra;

	ft_r_s(a, 0, 1);
	ra = ra_back_p(a, b, count - 1);
	if (!ra)
		return (NULL);
	ra->function_id = 2;
	ft_rr_s(a, 0, 1);
	return (max_methode(ra, back_rr(a, b, count), 0, 0));
}

static t_methode	*back_rr(int *a, int *b, int count)
{
	t_methode	*rra;

	ft_rr_s(a, 0, 1);
	rra = rra_back_p(a, b, count - 1);
	if (!rra)
		return (NULL);
	rra->function_id = 5;
	ft_r_s(a, 0, 1);
	return (max_methode(rra, back_s(a, b, count), 0, 0));
}

static t_methode	*back_s(int *a, int *b, int count)
{
	t_methode	*sa;

	ft_s_s(a, 0, 1);
	sa = sa_back_p(a, b, count - 1);
	if (!sa)
		return (NULL);
	sa->function_id = 8;
	ft_s_s(a, 0, 1);
	return (sa);
}

t_methode	*max_methode(t_methode *one, t_methode *two,
		t_methode *three, t_methode *four)
{
	t_methode	*temp;

	temp = one;
	if (two && (two->value > temp->value))
	{
		free(temp);
		temp = two;
	}
	else
		free(two);
	if (three && (three->value > temp->value))
	{
		free(temp);
		temp = three;
	}
	else
		free(three);
	if (four && (four->value > temp->value))
	{
		free(temp);
		temp = four;
	}
	else
		free(four);
	return (temp);
}
