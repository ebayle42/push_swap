/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmorand <trmorand@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:13:50 by trmorand          #+#    #+#             */
/*   Updated: 2026/11/18 14:13:51 by trmorand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int flag_cmp(char *argv, char *cmp)
{
	int i;

	i = 0;
	while (cmp[i])
	{
		if (argv[i + 2] != cmp[i])
			return (-1);
		i++;
	}
	if (argv[i + 2] != '\0')
		return (-1);
	return (0);
}

static int	check_flag(char *argv, int *count)
{
	if (flag_cmp(argv, "adaptive") == 0)
		*count = *count / 10 * 10 + 1;
	else if (flag_cmp(argv, "complex") == 0)
		*count = *count / 10 * 10 + 2;
	else if (flag_cmp(argv, "medium") == 0)
		*count = *count / 10 * 10 + 3;
	else if (flag_cmp(argv, "simple") == 0)
		*count = *count / 10 * 10 + 4;
	else if (flag_cmp(argv, "bench") == 0)
		*count = *count  % 10 + 10;
	else
		return (-1);
	return (0);
}
int	push_swap(char **argv, int argc, int *first)
{
	int	cc;
	int	count;

	cc = 1;
	count = 1;
	while (cc < argc && argv[cc][0] == '-' && argv[cc][1] == '-')
	{
		if (check_flag(argv[cc], &count) == -1)
			break ;
		cc++;
	}
	*first = cc;
	if (cc >= argc)
		return (0);
	return (count);
}

//
//	 /\___/\
//	(  * .* )
//	/ > 💙 <\
// /_   _   _\
// | |_| |_| |_
// ------------
// | We Enjoy |
// |    𝟒𝟐    |
// | 	𝟒𝟐    |
// |__________|
//
//
