/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:33:22 by geymat            #+#    #+#             */
/*   Updated: 2024/01/13 13:18:48 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static t_methode	*back_r(int *a, int *b, int count);
static t_methode	*back_rr(int *a, int *b, int count);
t_methode			*sb_back_p(int *a, int *b, int count);

void	sb_clear(int *a, int *b, t_methode **res)
{
	free(*res);
	ft_s_s(0, b, 0);
	*res = sb_back_p(a, b, DEPTH);
}

t_methode	*sb_back_p(int *a, int *b, int count)
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
	return (max_methode(ra, rb, rr, back_rr(a, b, count)));
}

static t_methode	*back_rr(int *a, int *b, int count)
{
	t_methode	*rra;
	t_methode	*rrb;
	t_methode	*rrr;
	t_methode	*actual;

	ft_rr_s(a, 0, 1);
	rra = rra_back_p(a, b, count - 1);
	if (!rra)
		return (NULL);
	rra->function_id = 5;
	ft_rr_s(0, b, 1);
	rrr = rrr_back_p(a, b, count - 1);
	if (!rrr)
		return (free_null(rra, 0, 0, 0));
	rrr->function_id = 7;
	ft_r_s(a, 0, 1);
	rrb = rrb_back_p(a, b, count - 1);
	if (!rrb)
		return (free_null(rra, rrr, 0, 0));
	rrb->function_id = 6;
	ft_r_s(0, b, 1);
	actual = methode_newval(a, count - 1);
	if (actual)
		actual->function_id = 9;
	return (max_methode(rra, rrb, rrr, actual));
}
