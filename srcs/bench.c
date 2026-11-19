/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmorand <trmorand@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 04:33:25 by trmorand          #+#    #+#             */
/*   Updated: 2026/11/19 17:00:26 by trmorand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*run_bench(int mode, t_ps *ps, double disorder)
{
	if (mode == 4 || (mode == 1 && disorder < 0.2))
		return ("Simple : O(n^2)");
	else if (mode == 3 || (mode == 1 && disorder < 0.5))
		return ("Medium : O(n sqrt(n))");
	else if (ps->a.size <= 5)
		return ("Complex : O(n log n)");
	return (0);
}

static void	put_count(char *name, int n)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(n, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_ops(t_ps *ps)
{
	put_count("sa", ps->cnt[0]);
	put_count("sb", ps->cnt[1]);
	put_count("ss", ps->cnt[2]);
	put_count("pa", ps->cnt[3]);
	put_count("pb", ps->cnt[4]);
	put_count("ra", ps->cnt[5]);
	put_count("rb", ps->cnt[6]);
	put_count("rr", ps->cnt[7]);
	put_count("rra", ps->cnt[8]);
	put_count("rrb", ps->cnt[9]);
	put_count("rrr", ps->cnt[10]);
}

void	print_bench(t_ps *ps, int mode, double disorder)
{
	int	pct;

	pct = (int)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(pct / 100, 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd(pct % 100 / 10, 2);
	ft_putnbr_fd(pct % 10, 2);
	ft_putstr_fd("%", 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd((char *)run_bench(mode % 10, ps, disorder), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(ps->ops, 2);
	ft_putstr_fd("\n", 2);
	print_ops(ps);
}
