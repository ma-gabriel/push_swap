/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:09:06 by geymat            #+#    #+#             */
/*   Updated: 2024/01/22 19:00:17 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stacks(int *num, char ***str, int **a, int **b)
{
	int	mallocated;

	mallocated = (*num == 1);
	if (*num == 1)
	{
		*str = ft_split(*str[0], ' ');
		if (!*str)
			return (0);
		*num = ft_bigstrlen(*str);
	}
	*a = malloc(((*num) + 1) * sizeof(int));
	if (!(*a))
		return (free_the_split(*str), 0);
	(*a)[0] = *num;
	*b = malloc(((*num) + 1) * sizeof(int));
	if (!(*b))
		return (free(a), free_the_split(*str), 0);
	(*b)[0] = 0;
	return (1 + mallocated);
}

int	inferior(int num, int *a)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (++i <= a[0])
		if (a[i] < num)
			res++;
	return (res);
}

void	annihilator(int **a)
{
	int	i;
	int	*res;

	res = malloc((**a + 1) * sizeof(int));
	if (!res)
	{
		free(a);
		return ;
	}
	res[0] = **a;
	i = 0;
	while (++i <= **a)
		res[i] = inferior(*(*a + i), *a);
	free(*a);
	*a = res;
}

int	check_error(char **str, int num, int *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < num)
		if ((long) a[i + 1] != ft_atol((const char *) str[num - 1 - i]))
			return (write(1, "Error\n", 6));
	i = 0;
	while (++i < *a)
	{
		j = i;
		while (++j <= *a)
			if (a[i] == a[j])
				return (write(1, "Error\n", 6));
	}
	return (write(1, NULL, 0));
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	i;
	int	j;

	argc --;
	argv ++;
	j = create_stacks(&argc, &argv, &a, &b);
	if (!j)
		return (0);
	i = -1;
	while (++i < argc)
		a[i + 1] = (int) ft_atol((const char *) argv[argc - 1 - i]);
	if (!check_error(argv, argc, a))
	{
		annihilator(&a);
		ft_pushswap(a, b);
	}
	if (j == 2)
		free_the_split(argv);
	free(a);
	free(b);
	return (0);
}
