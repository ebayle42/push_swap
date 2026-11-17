/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmorand <trmorand@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 22:02:00 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/17 14:44:18 by trmorand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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

void	qs_a(t_ps *ps, int n, int lo, t_pivot pick);
void	qs_b(t_ps *ps, int n, int lo, t_pivot pick);
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
int		fill(t_ps *ps, char **argv, int first, int n);
void	check_algo(int mode, t_ps *ps);
void	to_rank(t_ps *ps, int n);
void	minmax_sort(t_ps *ps);
void	range_sort(t_ps *ps);
void	quick_sort(t_ps *ps);

#endif
