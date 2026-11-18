/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmorand <trmorand@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:13:43 by trmorand          #+#    #+#             */
/*   Updated: 2026/11/18 14:13:44 by trmorand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

static int	to_int(const char *str, int *out)
{
	int			i;
	int			sign;
	long int	result;
	int			start;

	result = 0;
	i = 0;
	sign = get_sign(str, &i);
	start = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (-1);
		i++;
	}
	if (i == start || str[i] != '\0')
		return (-1);
	*out = result * sign;
	return (0);
}

int	fill(t_ps *ps, char **argv, int first, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		if (to_int(argv[first + i], &ps->a.v[i]) == -1)
			return (-1);
		j = 0;
		while (j < i)
		{
			if (ps->a.v[j] == ps->a.v[i])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	rank_of(t_stack *a, int n, int i)
{
	int	r;
	int	j;

	r = 0;
	j = 0;
	while (j < n)
	{
		if (a->v[j] < a->v[i])
			r++;
		j++;
	}
	return (r);
}

void	to_rank(t_ps *ps, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps->b.v[i] = rank_of(&ps->a, n, i);
		i++;
	}
	i = 0;
	while (i <  n)
	{
		ps->a.v[i] = ps->b.v[i];
		i++;
	}
}
