/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 23:26:37 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/14 23:26:50 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pivot_median(int lo, int n)
{
	return (lo + n / 2);
}

void	quick_sort(t_ps *ps)
{
	qs_a(ps, ps->a.size, 0, pivot_median);
}
