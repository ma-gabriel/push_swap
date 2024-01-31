/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:30:36 by geymat            #+#    #+#             */
/*   Updated: 2024/01/31 03:54:28 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <stdlib.h>
# include <unistd.h>
# ifndef DEPTH
#  define DEPTH 7
# endif

typedef struct s_methode
{
	ssize_t	value;
	size_t	function_id;
}	t_methode;

t_methode	*max_methode(t_methode *one, t_methode *two,
				t_methode *three, t_methode *four);
t_methode	*ft_back_p(int *a, int *b, int count);
t_methode	*pa_back_p(int *a, int *b, int count);
t_methode	*pb_back_p(int *a, int *b, int count);
t_methode	*sa_back_p(int *a, int *b, int count);
t_methode	*sb_back_p(int *a, int *b, int count);
t_methode	*ss_back_p(int *a, int *b, int count);
t_methode	*ra_back_p(int *a, int *b, int count);
t_methode	*rb_back_p(int *a, int *b, int count);
t_methode	*rr_back_p(int *a, int *b, int count);
t_methode	*rra_back_p(int *a, int *b, int count);
t_methode	*rrb_back_p(int *a, int *b, int count);
t_methode	*rrr_back_p(int *a, int *b, int count);
t_methode	*methode_newval(int *a, int count);
t_methode	*free_null(t_methode *first, t_methode *second,
				t_methode *third, t_methode *fourth);
void		ft_s_s(int *a, int *b, int silence);
void		ft_r_s(int *a, int *b, int silence);
void		ft_rr_s(int *a, int *b, int silence);
int			ft_pb_s(int *a, int *b, int silence);
int			ft_pa_s(int *a, int *b, int silence);
int			free_the_split(char **string);
int			ft_sorted(int *a);
void		pa_clear(int *a, int *b, t_methode **res);
void		pb_clear(int *a, int *b, t_methode **res);
void		ra_clear(int *a, int *b, t_methode **res);
void		rb_clear(int *a, int *b, t_methode **res);
void		rr_clear(int *a, int *b, t_methode **res);
void		rra_clear(int *a, int *b, t_methode **res);
void		rrb_clear(int *a, int *b, t_methode **res);
void		rrr_clear(int *a, int *b, t_methode **res);
void		sa_clear(int *a, int *b, t_methode **res);
void		sb_clear(int *a, int *b, t_methode **res);
void		ss_clear(int *a, int *b, t_methode **res);

#endif
