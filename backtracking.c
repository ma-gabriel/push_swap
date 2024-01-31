/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:40:30 by geymat            #+#    #+#             */
/*   Updated: 2024/01/13 10:15:37 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static void	actual_backtracking(int *a, int *b, t_methode **res)
{
	while ((!ft_sorted(a) || *b) && *res)
	{
		if ((*res)->function_id == 0)
			pa_clear(a, b, res);
		else if ((*res)->function_id == 1)
			pb_clear(a, b, res);
		else if ((*res)->function_id == 2)
			ra_clear(a, b, res);
		else if ((*res)->function_id == 3)
			rb_clear(a, b, res);
		else if ((*res)->function_id == 4)
			rr_clear(a, b, res);
		else if ((*res)->function_id == 5)
			rra_clear(a, b, res);
		else if ((*res)->function_id == 6)
			rrb_clear(a, b, res);
		else if ((*res)->function_id == 7)
			rrr_clear(a, b, res);
		else if ((*res)->function_id == 8)
			sa_clear(a, b, res);
		else if ((*res)->function_id == 9)
			sb_clear(a, b, res);
		else if ((*res)->function_id == 10)
			ss_clear(a, b, res);
	}
}

int	ft_sort_backtrack(int *a, int *b)
{
	t_methode	*res;

	if (!ft_sorted(a))
	{
		res = ft_back_p(a, b, DEPTH);
		actual_backtracking(a, b, &res);
		if (res)
		{
			free(res);
			return (1);
		}
		return (0);
	}
	return (1);
}
