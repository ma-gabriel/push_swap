/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:35:19 by geymat            #+#    #+#             */
/*   Updated: 2024/01/13 13:18:25 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static t_methode	*back_r(int *a, int *b, int count);
t_methode			*rr_back_p(int *a, int *b, int count);
static t_methode	*back_s(int *a, int *b, int count);

void	rr_clear(int *a, int *b, t_methode **res)
{
	free(*res);
	ft_r_s(a, b, 0);
	*res = rr_back_p(a, b, DEPTH);
}

t_methode	*rr_back_p(int *a, int *b, int count)
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
	t_methode	*rb;
	t_methode	*rr;

	ft_r_s(a, 0, 1);
	ra = ra_back_p(a, b, count - 1);
	if (!ra)
		return (NULL);
	ra->function_id = 2;
	ft_rr_s(a, 0, 1);
	ft_r_s(0, b, 1);
	rb = rb_back_p(a, b, count - 1);
	if (!rb)
		return (free_null(ra, 0, 0, 0));
	rb->function_id = 3;
	ft_r_s(a, 0, 1);
	rr = rr_back_p(a, b, count - 1);
	if (!rr)
		return (free_null(ra, rb, 0, 0));
	rr->function_id = 4;
	ft_rr_s(a, b, 1);
	return (max_methode(ra, rb, rr, back_s(a, b, count)));
}

static t_methode	*back_s(int *a, int *b, int count)
{
	t_methode	*sb;
	t_methode	*sa;
	t_methode	*ss;
	t_methode	*actual;

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
	actual = methode_newval(a, count - 1);
	if (actual)
		actual->function_id = 4;
	return (max_methode(sa, sb, ss, actual));
}
