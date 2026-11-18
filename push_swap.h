/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:05:10 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/17 20:05:10 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int	*v;
	int	size;
}	t_stack;

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
	int		ops;
}	t_ps;

typedef int	(*t_pivot)(int lo, int n);

/* parsing (Tristan/pushswap_parse.c, Tristan/parse_num.c) */
int		push_swap(char **argv, int argc, int *first);
int		fill(t_ps *ps, char **argv, int first, int n);
void	to_rank(t_ps *ps, int n);

/* operations (Enzo/ops_*.c) */
void	put_op(t_ps *ps, const char *s);
void	swap(t_stack *s);
void	push(t_stack *dst, t_stack *src);
void	rotate(t_stack *s);
void	rrotate(t_stack *s);
void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);
void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);

/* utils (a ecrire) */
int		is_sorted(t_stack *s);
int		pos_of_min(t_stack *s);
int		pos_of_max(t_stack *s);
int		cost(int pos, int size);
void	top_a(t_ps *ps, int pos);
void	sort_three(t_ps *ps);
void	push_back_max(t_ps *ps);

/* algos */
void	check_algo(int mode, t_ps *ps, double disorder);
void	minmax_sort(t_ps *ps);
void	range_sort(t_ps *ps);
void	quick_sort(t_ps *ps);
void	qs_a(t_ps *ps, int n, int lo, t_pivot pick);
void	qs_b(t_ps *ps, int n, int lo, t_pivot pick);
void	sort_small_a(t_ps *ps, int n);
void	push_small_b(t_ps *ps, int n);

/* disorder et bench (a ecrire) */
double	compute_disorder(t_stack *a);
void	print_bench(t_ps *ps, int mode, double disorder);

#endif
