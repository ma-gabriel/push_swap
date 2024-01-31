/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:40:12 by geymat            #+#    #+#             */
/*   Updated: 2024/01/19 18:14:38 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
}	t_stack;

void		ft_s(int *a, int *b);
void		ft_rr(int *a, int *b);
void		ft_r(int *a, int *b);
void		ft_pb(int *a, int *b);
void		ft_pa(int *a, int *b);
char		**ft_split(char const *s, char c);
int			free_the_split(char **string);
void		ft_sort(int *a, int *b);
int			ft_sorted(int *a);
int			ft_sort_backtrack(int *a, int *b);
long int	ft_atol(const char *str);
void		ft_pushswap(int *a, int *b);
size_t		ft_bigstrlen(char **string);
int			ft_index_max(int *a);
int			ft_selection_loop(t_stack stacks, int stocked, int second);

#endif
