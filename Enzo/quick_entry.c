/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:05:26 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/17 20:05:26 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pivot_median(int lo, int n)
{
	return (lo + n / 2);
}

void	sort_small_a(t_ps *ps, int n)
{
	if (n == 3 && ps->a.size == 3)
	{
		sort_three(ps);
		return ;
	}
	if (ps->a.v[0] > ps->a.v[1])
		sa(ps);
	if (n == 3 && ps->a.v[1] > ps->a.v[2])
	{
		pb(ps);
		sa(ps);
		pa(ps);
	}
	if (ps->a.v[0] > ps->a.v[1])
		sa(ps);
}

void	push_small_b(t_ps *ps, int n)
{
	if (n == 3 && ps->b.v[0] < ps->b.v[1])
		sb(ps);
	if (n == 3)
		pa(ps);
	if (n >= 2 && ps->b.v[0] < ps->b.v[1])
		sb(ps);
	if (n >= 2)
		pa(ps);
	if (n == 3 && ps->a.v[0] > ps->a.v[1])
		sa(ps);
	pa(ps);
}

void	quick_sort(t_ps *ps)
{
	qs_a(ps, ps->a.size, 0, pivot_median);
}
