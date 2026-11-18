/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:37:52 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/18 17:37:52 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	long	inv;
	long	pairs;
	int		i;
	int		j;

	if (a->size < 2)
		return (0.0);
	inv = 0;
	i = 0;
	while (i < a->size - 1)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->v[i] > a->v[j])
				inv++;
			j++;
		}
		i++;
	}
	pairs = (long)a->size * (a->size - 1) / 2;
	return ((double)inv / pairs);
}
