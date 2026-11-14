/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 23:28:40 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/14 23:28:58 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	extract_one(t_ps *ps, int *nmax)
{
	int	pmin;
	int	pmax;

	pmin = pos_of_min(&ps->a);
	pmax = pos_of_max(&ps->a);
	if (cost(pmin, ps->a.size) <= cost(pmax, ps->a.size))
	{
		top_a(ps, pmin);
		pb(ps);
		if (ps->b.size > 1)
			rb(ps);
	}
	else
	{
		top_a(ps, pmax);
		pb(ps);
		(*nmax)++;
	}
}
static void	minmax_rebuild(t_ps *ps, int nmax)
{
	while (nmax-- > 0)
	{
		pa(ps);
		ra(ps);
	}
	while (ps->b.size > 0)
	{
		if (ps->b.size > 1)
			rrb(ps);
		pa(ps);
	}
}
void	minmax_sort(t_ps *ps)
{
	int	nmax;

	nmax = 0;
	while (ps->a.size > 3 && !is_sorted(&ps->a))
		extract_one(ps, &nmax);
	sort_three(ps);
	minmax_rebuild(ps, nmax);
}
