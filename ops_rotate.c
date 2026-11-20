/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmorand <trmorand@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:05:31 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/19 04:19:53 by trmorand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	rotate(&ps->a);
	put_op(ps, "ra", 5);
}

void	rb(t_ps *ps)
{
	rotate(&ps->b);
	put_op(ps, "rb", 6);
}

void	rr(t_ps *ps)
{
	rotate(&ps->a);
	rotate(&ps->b);
	put_op(ps, "rr", 7);
}

void	rra(t_ps *ps)
{
	rrotate(&ps->a);
	put_op(ps, "rra", 8);
}

void	rrb(t_ps *ps)
{
	rrotate(&ps->b);
	put_op(ps, "rrb", 9);
}
