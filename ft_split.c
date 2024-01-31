/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:30:07 by geymat            #+#    #+#             */
/*   Updated: 2024/01/13 13:16:21 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_bigstrlen(char **string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i ++;
	return (i);
}

int	free_the_split(char **string)
{
	int	i;

	i = 0;
	while (string[i])
		i ++;
	while (i)
		free(string[--i]);
	free(string);
	return (42);
}

static int	create_new_subarray(char const *s,
		char c, size_t *vars[2], char **res)
{
	size_t	i;

	if (*s != c)
	{
		if (*vars[1] + 1)
			res[*vars[1]][(*vars[0])++] = 0;
		i = 0;
		while (s[i] != c && s[i])
			i++;
		res[++*vars[1]] = (char *) malloc(i + 1);
		if (!res[*vars[1]])
		{
			while (--*vars[1] + 1)
				free(res[*vars[1]]);
			free(res);
			return (0);
		}
		*vars[0] = 0;
	}
	return (1);
}

static int	fill_the_array(char const *s, char **res, char c)
{
	size_t	nw;
	size_t	j;
	size_t	i;
	size_t	*vars[2];

	nw = 1;
	i = 0;
	j = -1;
	vars[0] = &i;
	vars[1] = &j;
	while (*++s)
	{
		if (nw &&!create_new_subarray(s, c, vars, res))
			return (0);
		nw = 1;
		if (*s != c)
		{
			res[j][i++] = *s;
			nw = 0;
		}
	}
	if (j + 1)
		res[j][i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	nw;
	size_t	cw;
	char	**res;

	i = -1;
	nw = 1;
	cw = 0;
	while (s[++i])
	{
		if (nw && s[i] != c)
			cw++;
		nw = 1;
		if (s[i] != c)
			nw = 0;
	}
	res = (char **) malloc((cw + 1) * sizeof(char *));
	if (!res || !fill_the_array(s - 1, res, c))
		return (NULL);
	res[cw] = 0;
	return (res);
}
