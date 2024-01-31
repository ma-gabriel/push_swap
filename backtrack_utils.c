/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:22:44 by geymat            #+#    #+#             */
/*   Updated: 2024/01/13 11:42:19 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static ssize_t	testers(int *a)
{
	int		i;
	ssize_t	res;
	int		temp;

	res = 0;
	i = 0;
	temp = 0;
	while (++i < *a)
	{
		if (a[i] == a[i + 1] + 1)
			res += ++temp * 3;
		else
			temp = 0;
	}
	i = 0;
	temp = 0;
	while (++i < *a)
	{
		if (a[i] == a[i + 1] - 1)
			res -= ++temp * 2;
		else
			temp = 0;
	}
	return (res);
}

t_methode	*methode_newval(int *a, int count)
{
	t_methode	*res;

	res = malloc(sizeof(t_methode));
	if (!res)
		return (NULL);
	res->value = testers(a) + (size_t) count;
	res->function_id = 0;
	return (res);
}

t_methode	*free_null(t_methode *first, t_methode *second,
				t_methode *third, t_methode *fourth)
{
	if (first)
		free(first);
	if (second)
		free(second);
	if (third)
		free(third);
	if (fourth)
		free(fourth);
	return (NULL);
}
