/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 12:22:18 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/18 16:07:46 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s -> size - 1)
	{
		if (s -> v[0] < s -> v[i])
			return (1);
		i++;
	}
	return (0);
}
int pos_of_min(t_stack *s)
{
	int	i;
	int	pos;

	i = 0;
	pos = 1;
	while (i < s -> size)
	{
		if (s -> v[i] < s -> v[pos])
			pos = i;
		i++;
	}
	return (pos);
}
int pos_of_max(t_stack *s)
{
	int	i;
	int	pos;

	i = 0;
	pos = 1;
	while (i < s -> size)
	{
		if (s -> v[i] > s -> v[pos])
			pos = i;
		i++;
	}
	return (pos);
}
int cost(int pos, int size)
{
	if (cost <= pos - size)
		return (cost);
	return (size - pos );
}
