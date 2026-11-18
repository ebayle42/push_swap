/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmorand <trmorand@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:14:00 by trmorand          #+#    #+#             */
/*   Updated: 2026/11/18 14:14:01 by trmorand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_algo(int mode, t_ps *ps, double disorder)
{
	if (mode == 1 && disorder < 0.2)
		minmax_sort(ps);
	else if (mode == 1 && disorder < 0.5)
		range_sort(ps);
	else if (mode == 1)
		quick_sort(ps);
	else if (mode == 2)
		quick_sort(ps);
	else if (mode == 3)
		range_sort(ps);
	else if (mode == 4)
		minmax_sort(ps);
}

void	check_algo(int mode, t_ps *ps, double disorder)
{
	run_algo(mode % 10, ps, disorder);
}
