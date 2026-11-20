/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:14:00 by trmorand          #+#    #+#             */
/*   Updated: 2026/11/19 19:16:24 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_algo(int mode, t_ps *ps, double disorder)
{
	if (mode == 4 || (mode == 1 && (ps->a.size <= 5 || disorder < 0.2)))
		minmax_sort(ps);
	else if (mode == 3 || (mode == 1 && disorder < 0.5))
		range_sort(ps);
	else
		quick_sort(ps);
}

void	check_algo(int mode, t_ps *ps, double disorder)
{
	run_algo(mode % 10, ps, disorder);
}
