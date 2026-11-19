/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmorand <trmorand@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:14:00 by trmorand          #+#    #+#             */
/*   Updated: 2026/11/19 17:00:51 by trmorand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_algo(int mode, t_ps *ps, double disorder)
{
	if (ps->a.size <= 5 || mode == 4 || (mode == 1 && disorder < 0.2))
		minmax_sort(ps);
	else if (mode == 3 || (mode == 1 && disorder < 0.5))
		range_sort(ps);
	else if (ps->a.size <= 5)
		quick_sort(ps);
}

void	check_algo(int mode, t_ps *ps, double disorder)
{
	run_algo(mode % 10, ps, disorder);
}
