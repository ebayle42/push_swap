/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_base_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 22:08:07 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/15 22:08:11 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps)
{
	swap(&ps->a);
	put_op(ps, "sa");
}

void	sb(t_ps *ps)
{
	swap(&ps->b);
	put_op(ps, "sb");
}

void	ss(t_ps *ps)
{
	swap(&ps->a);
	swap(&ps->b);
	put_op(ps, "ss");
}

void	pa(t_ps *ps)
{
	push(&ps->a, &ps->b);
	put_op(ps, "pa");
}

void	pb(t_ps *ps)
{
	push(&ps->b, &ps->a);
	put_op(ps, "pb");
}
