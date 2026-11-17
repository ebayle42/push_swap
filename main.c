/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:05:15 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/17 20:05:15 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_error(t_ps *ps)
{
	free(ps->a.v);
	free(ps->b.v);
	write(2, "Error\n", 6);
	return (1);
}

static int	init_stacks(t_ps *ps, int n)
{
	ps->a.v = malloc(sizeof(int) * n);
	ps->b.v = malloc(sizeof(int) * n);
	ps->a.size = n;
	ps->b.size = 0;
	ps->ops = 0;
	if (!ps->a.v || !ps->b.v)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		mode;
	int		first;
	double	disorder;

	mode = push_swap(argv, argc, &first);
	if (mode == 0)
		return (0);
	if (init_stacks(&ps, argc - first) == -1
		|| fill(&ps, argv, first, argc - first) == -1)
		return (ps_error(&ps));
	to_rank(&ps, ps.a.size);
	disorder = compute_disorder(&ps.a);
	if (disorder > 0)
		check_algo(mode, &ps, disorder);
	if (mode >= 10)
		print_bench(&ps, mode, disorder);
	free(ps.a.v);
	free(ps.b.v);
	return (0);
}
