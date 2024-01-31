/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:31:21 by geymat            #+#    #+#             */
/*   Updated: 2024/01/13 13:17:54 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static t_methode	*back_r(int *a, int *b, int count);
static t_methode	*back_rr(int *a, int *b, int count);
t_methode			*pb_back_p(int *a, int *b, int count);
static t_methode	*back_s(int *a, int *b, int count);

void	pb_clear(int *a, int *b, t_methode **res)
{
	free(*res);
	ft_pb_s(a, b, 0);
	*res = pb_back_p(a, b, DEPTH);
}

t_methode	*pb_back_p(int *a, int *b, int count)
{
	t_methode	*pb;
	t_methode	*actual;
	int			worked;

	if (!count || (ft_sorted(a) && !(*b)))
		return (methode_newval(a, count));
	worked = ft_pb_s(a, b, 1);
	pb = pb_back_p(a, b, count - 1);
	if (!pb)
		return (NULL);
	pb->value *= worked;
	pb->function_id = 1;
	if (worked)
		ft_pa_s(a, b, 1);
	actual = methode_newval(a, count - 1);
	if (!actual)
		return (free_null(pb, 0, 0, 0));
	actual->function_id = 1;
	return (max_methode(pb, back_r(a, b, count), actual, 0));
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
	return (max_methode(ra, rb, rr, back_rr(a, b, count)));
}

static t_methode	*back_rr(int *a, int *b, int count)
{
	t_methode	*rra;
	t_methode	*rrb;
	t_methode	*rrr;

	ft_rr_s(a, 0, 1);
	rra = rra_back_p(a, b, count - 1);
	if (!rra)
		return (NULL);
	rra->function_id = 5;
	ft_r_s(a, 0, 1);
	ft_rr_s(0, b, 1);
	rrb = rrb_back_p(a, b, count - 1);
	if (!rrb)
		return (free_null(rra, 0, 0, 0));
	rrb->function_id = 6;
	ft_rr_s(a, 0, 1);
	rrr = rrr_back_p(a, b, count - 1);
	if (!rrr)
		return (free_null(rra, rrb, 0, 0));
	rrr->function_id = 7;
	ft_r_s(a, b, 1);
	return (max_methode(rra, rrb, rrr, back_s(a, b, count)));
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
