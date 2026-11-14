/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 23:27:56 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/14 23:28:08 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	range = 15;
	if (ps->a.size > 100)
		range = 30;
	while (ps->a.size > 0)
		range_step(ps, &i, range);
	push_back_max(ps);
}
