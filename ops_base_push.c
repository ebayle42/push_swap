/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_base_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:05:37 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/21 16:19:07 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps)
{
	swap(&ps->a);
	put_op(ps, "sa", 0);
}

void	sb(t_ps *ps)
{
	swap(&ps->b);
	put_op(ps, "sb", 1);
}

void	ss(t_ps *ps)
{
	swap(&ps->a);
	swap(&ps->b);
	put_op(ps, "ss", 2);
}

void	pa(t_ps *ps)
{
	push(&ps->a, &ps->b);
	put_op(ps, "pa", 3);
}

void	pb(t_ps *ps)
{
	push(&ps->b, &ps->a);
	put_op(ps, "pb", 4);
}
