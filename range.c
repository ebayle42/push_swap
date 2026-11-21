/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:05:21 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/21 16:18:30 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

static void	range_step(t_ps *ps, int *i, int range)
{
	int	x;

	x = ps->a.v[0];
	if (x <= *i + range)
	{
		pb(ps);
		if (x <= *i && ps->b.size > 1)
			rb(ps);
		(*i)++;
	}
	else
		ra(ps);
}

void	range_sort(t_ps *ps)
{
	int	i;
	int	range;

	i = 0;
	range = isqrt(2 * ps->a.size);
	while (ps->a.size > 0)
		range_step(ps, &i, range);
	push_back_max(ps);
}
