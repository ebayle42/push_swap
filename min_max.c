/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 15:16:14 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/21 16:17:02 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define WINDOW 4

static int	b_target(t_stack *b, int x)
{
	int	i;
	int	prev;

	if (b->size < 2)
		return (0);
	if (x > b->v[pos_of_max(b)] || x < b->v[pos_of_min(b)])
		return (pos_of_max(b));
	i = 0;
	while (i < b->size)
	{
		prev = b->v[(i + b->size - 1) % b->size];
		if (b->v[i] < x && prev > x)
			return (i);
		i++;
	}
	return (0);
}

static void	try_index(t_ps *ps, int ia, int *best)
{
	int	ib;
	int	c;

	ib = b_target(&ps->b, ps->a.v[ia]);
	c = cost(ia, ps->a.size) + cost(ib, ps->b.size);
	if (best[2] < 0 || c < best[2])
	{
		best[0] = ia;
		best[1] = ib;
		best[2] = c;
	}
}

static void	insert_cheapest(t_ps *ps)
{
	int	best[3];
	int	i;

	best[2] = -1;
	i = 0;
	while (i < ps->a.size && i < WINDOW)
		try_index(ps, i++, best);
	i = ps->a.size - WINDOW;
	if (i < WINDOW)
		i = WINDOW;
	while (i < ps->a.size)
		try_index(ps, i++, best);
	top_a(ps, best[0]);
	top_b(ps, best[1]);
	pb(ps);
}

static void	small_sort(t_ps *ps)
{
	while (ps->a.size > 3)
	{
		top_a(ps, pos_of_min(&ps->a));
		pb(ps);
	}
	sort_three(ps);
	while (ps->b.size > 0)
		pa(ps);
}

void	minmax_sort(t_ps *ps)
{
	if (ps->a.size <= 5)
	{
		small_sort(ps);
		return ;
	}
	while (ps->a.size > 0)
		insert_cheapest(ps);
	push_back_max(ps);
}
