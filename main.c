/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:05:15 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/20 18:26:46 by ebayle           ###   ########.fr       */
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
	int	i;

	i = 0;
	ps->a.v = malloc(sizeof(int) * n);
	ps->b.v = malloc(sizeof(int) * n);
	ps->a.size = n;
	ps->b.size = 0;
	ps->ops = 0;
	if (!ps->a.v || !ps->b.v)
		return (-1);
	while (i < 11)
	{
		ps->cnt[i] = 0;
		i++;
	}
	return (0);
}

static void run_sort(t_ps *ps, int mode)
{
	double	disorder;
	to_rank(ps, ps -> a.size);
	disorder = compute_disorder(&ps -> a);
	if (disorder > 0)
		check_algo(mode, ps, disorder);
	if (mode >= 10)
		print_bench(ps, mode, disorder);
}


int	main(int argc, char **argv)
{
	t_ps	ps;
	int		mode;
	int		first;
	int		n;
	char	**args;

	mode = push_swap(argv, argc, &first);
	if (mode == 0)
		return (0);
	args = get_args(argv, argc, first, &n);
	if (!args)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (init_stacks(&ps, n) == -1 || fill(&ps, args, 0, n) == -1)
	{
		free_args(args);
		return (ps_error(&ps));
	}
	free_args(args);
	run_sort(&ps, mode);
	free(ps.a.v);
	free(ps.b.v);
	return (0);
}
