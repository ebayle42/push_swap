/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:05:33 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/21 16:19:10 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_op(t_ps *ps, const char *s, int id)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	write(1, "\n", 1);
	ps->ops++;
	ps->cnt[id]++;
}

void	swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->v[0];
	s->v[0] = s->v[1];
	s->v[1] = tmp;
}

void	push(t_stack *dst, t_stack *src)
{
	int	i;

	if (src->size == 0)
		return ;
	i = dst->size;
	while (i > 0)
	{
		dst->v[i] = dst->v[i - 1];
		i--;
	}
	dst->v[0] = src->v[0];
	dst->size++;
	i = 0;
	while (i < src->size - 1)
	{
		src->v[i] = src->v[i + 1];
		i++;
	}
	src->size--;
}

void	rotate(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size < 2)
		return ;
	tmp = s->v[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->v[i] = s->v[i + 1];
		i++;
	}
	s->v[s->size - 1] = tmp;
}

void	rrotate(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size < 2)
		return ;
	tmp = s->v[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->v[i] = s->v[i - 1];
		i--;
	}
	s->v[0] = tmp;
}
