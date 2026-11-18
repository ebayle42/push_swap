/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 12:22:18 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/18 14:19:43 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	is_sorted(t_stack *s)
{
	if (s ->v [0] < s -> v[ft_lstsize(s) - 1])
		return (1);
	return (0);
}
int pos_of_min(t_stack *s)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (s)
	{
		if (s -> v[i] > s -> v[i])
		{
			min = s -> v[i];
		}
		i++;
	}
	return (min);
}
int pos_of_min(t_stack *s)
{

}
int cost(t_stack *s)
{

}
void top_a(t_ps *ps, int pos)
{

}