/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 23:32:25 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/14 23:34:37 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	if_same(const char *a, const char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a == *b);
}

t_algo	algo(const char *s)
{
	if (if_same(s, "--minmax"))
		return (min_max);
	if (if_same(s, "--range"))
		return (range);
	if (if_same(s, "--quick"))
		return (quick);
	if (if_same(s, "--adaptive"))
		return (adaptive);
	return (NULL);
}
