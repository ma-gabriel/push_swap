/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb_backtrack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:36:48 by geymat            #+#    #+#             */
/*   Updated: 2024/01/13 13:18:32 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static t_methode	*back_r(int *a, int *b, int count);
static t_methode	*back_rr(int *a, int *b, int count);
t_methode			*rrb_back_p(int *a, int *b, int count);
static t_methode	*back_s(int *a, int *b, int count);

void	rrb_clear(int *a, int *b, t_methode **res)
{
	free(*res);
	ft_rr_s(0, b, 0);
	*res = rrb_back_p(a, b, DEPTH);
}

t_methode	*rrb_back_p(int *a, int *b, int count)
{
	t_methode	*pa;
	t_methode	*pb;
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
	worked = ft_pb_s(a, b, 1);
	pb = pb_back_p(a, b, count - 1);
	if (!pb)
		return (free_null(pa, 0, 0, 0));
	pb->value *= worked;
	pb->function_id = 1;
	if (worked)
		ft_pa_s(a, b, 1);
	return (max_methode(pa, pb, back_r(a, b, count), 0));
}

static t_methode	*back_r(int *a, int *b, int count)
{
	t_methode	*ra;

	ft_r_s(a, 0, 1);
	ra = ra_back_p(a, b, count - 1);
	if (!ra)
		return (NULL);
	ra->function_id = 2;
	ft_rr_s(a, b, 1);
	return (max_methode(ra, back_rr(a, b, count), 0, 0));
}

static t_methode	*back_rr(int *a, int *b, int count)
{
	t_methode	*rrb;
	t_methode	*rrr;
	t_methode	*actual;

	rrb = rrb_back_p(a, b, count - 1);
	if (!rrb)
		return (NULL);
	rrb->function_id = 6;
	ft_rr_s(a, 0, 1);
	rrr = rrr_back_p(a, b, count - 1);
	if (!rrr)
		return (free_null(rrb, 0, 0, 0));
	rrr->function_id = 7;
	ft_r_s(a, b, 1);
	actual = methode_newval(a, count - 1);
	if (!actual)
		return (free_null(rrb, rrr, 0, 0));
	actual->function_id = 6;
	return (max_methode(rrb, rrr, back_s(a, b, count), actual));
}

static t_methode	*back_s(int *a, int *b, int count)
{
	t_methode	*sb;
	t_methode	*sa;
	t_methode	*ss;

	ft_s_s(a, 0, 1);
	sa = sa_back_p(a, b, count - 1);
	if (!sa)
		return (NULL);
	sa->function_id = 8;
	ft_s_s(a, b, 1);
	sb = sb_back_p(a, b, count - 1);
	if (!sb)
		return (free_null(sa, 0, 0, 0));
	sb->function_id = 9;
	ft_s_s(a, 0, 1);
	ss = ss_back_p(a, b, count - 1);
	if (!ss)
		return (free_null(sa, sb, 0, 0));
	ss->function_id = 10;
	ft_s_s(a, b, 1);
	return (max_methode(sa, sb, ss, 0));
}
