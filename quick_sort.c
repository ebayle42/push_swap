/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:05:23 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/21 16:17:24 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	part_a(t_ps *ps, int pivot, int small)
{
	int	moved;
	int	rot;

	moved = 0;
	rot = 0;
	while (moved < small)
	{
		if (ps->a.v[0] < pivot)
		{
			pb(ps);
			moved++;
		}
		else
		{
			ra(ps);
			rot++;
		}
	}
	return (rot);
}

static int	part_b(t_ps *ps, int pivot, int big)
{
	int	moved;
	int	rot;

	moved = 0;
	rot = 0;
	while (moved < big)
	{
		if (ps->b.v[0] >= pivot)
		{
			pa(ps);
			moved++;
		}
		else
		{
			rb(ps);
			rot++;
		}
	}
	return (rot);
}

void	qs_a(t_ps *ps, int n, int lo, t_pivot pick)
{
	int	pivot;
	int	small;
	int	rot;

	if (n <= 1)
		return ;
	if (n <= 3)
	{
		sort_small_a(ps, n);
		return ;
	}
	pivot = pick(lo, n);
	small = pivot - lo;
	rot = part_a(ps, pivot, small);
	while (ps->a.size > n - small && rot-- > 0)
		rra(ps);
	qs_a(ps, n - small, pivot, pick);
	qs_b(ps, small, lo, pick);
}

void	qs_b(t_ps *ps, int n, int lo, t_pivot pick)
{
	int	pivot;
	int	big;
	int	rot;

	if (n == 0)
		return ;
	if (n <= 3)
	{
		push_small_b(ps, n);
		return ;
	}
	pivot = pick(lo, n);
	big = n - (pivot - lo);
	rot = part_b(ps, pivot, big);
	while (ps->b.size > n - big && rot-- > 0)
		rrb(ps);
	qs_a(ps, big, pivot, pick);
	qs_b(ps, n - big, lo, pick);
}
