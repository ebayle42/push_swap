/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 12:22:18 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/21 16:18:36 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size - 1)
	{
		if (s->v[i] > s->v[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	pos_of_min(t_stack *s)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < s->size)
	{
		if (s->v[i] < s->v[pos])
			pos = i;
		i++;
	}
	return (pos);
}

int	pos_of_max(t_stack *s)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < s->size)
	{
		if (s->v[i] > s->v[pos])
			pos = i;
		i++;
	}
	return (pos);
}

int	cost(int pos, int size)
{
	if (pos <= size - pos)
		return (pos);
	return (size - pos);
}

void	top_a(t_ps *ps, int pos)
{
	if (pos <= ps->a.size / 2)
	{
		while (pos-- > 0)
			ra(ps);
	}
	else
	{
		while (pos++ < ps->a.size)
			rra(ps);
	}
}
