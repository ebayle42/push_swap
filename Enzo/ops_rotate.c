/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 22:08:35 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/15 22:08:37 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	rotate(&ps->a);
	put_op(ps, "ra");
}

void	rb(t_ps *ps)
{
	rotate(&ps->b);
	put_op(ps, "rb");
}

void	rr(t_ps *ps)
{
	rotate(&ps->a);
	rotate(&ps->b);
	put_op(ps, "rr");
}

void	rra(t_ps *ps)
{
	rrotate(&ps->a);
	put_op(ps, "rra");
}

void	rrb(t_ps *ps)
{
	rrotate(&ps->b);
	put_op(ps, "rrb");
}
