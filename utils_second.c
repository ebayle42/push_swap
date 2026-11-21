/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:06:49 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/18 14:07:19 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_b(t_ps *ps, int pos)
{
	if (pos <= ps->b.size / 2)
	{
		while (pos-- > 0)
			rb(ps);
	}
	else
	{
		while (pos++ < ps->b.size)
			rrb(ps);
	}
}

void	sort_three(t_ps *ps)
{
	int	*v;

	if (ps->a.size == 2 && ps->a.v[0] > ps->a.v[1])
		sa(ps);
	if (ps->a.size != 3)
		return ;
	v = ps->a.v;
	if (pos_of_max(&ps->a) == 0)
		ra(ps);
	else if (pos_of_max(&ps->a) == 1)
		rra(ps);
	if (v[0] > v[1])
		sa(ps);
}

void	push_back_max(t_ps *ps)
{
	while (ps->b.size > 0)
	{
		top_b(ps, pos_of_max(&ps->b));
		pa(ps);
	}
}
