/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 22:02:00 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/15 22:03:17 by ebayle           ###   ########.fr       */
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

void	minmax_sort(t_ps *ps);
void	range_sort(t_ps *ps);
void	quick_sort(t_ps *ps);

#endif
