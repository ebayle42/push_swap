/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 10:00:00 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/20 10:00:00 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	count_all(char **argv, int argc, int first)
{
	int	i;
	int	total;
	int	w;

	i = first;
	total = 0;
	while (i < argc)
	{
		w = count_words(argv[i]);
		if (w == 0)
			return (-1);
		total += w;
		i++;
	}
	return (total);
}

void	free_args(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static int	add_split(char **tab, int *k, char *arg)
{
	char	**split;
	int		i;

	split = ft_split(arg, ' ');
	if (!split)
		return (-1);
	i = 0;
	while (split[i])
	{
		tab[*k] = split[i];
		(*k)++;
		i++;
	}
	tab[*k] = NULL;
	free(split);
	return (0);
}

char	**get_args(char **argv, int argc, int first, int *n)
{
	char	**tab;
	int		i;
	int		k;

	*n = count_all(argv, argc, first);
	if (*n <= 0)
		return (NULL);
	tab = malloc(sizeof(char *) * (*n + 1));
	if (!tab)
		return (NULL);
	tab[0] = NULL;
	k = 0;
	i = first;
	while (i < argc)
	{
		if (add_split(tab, &k, argv[i]) == -1)
		{
			free_args(tab);
			return (NULL);
		}
		i++;
	}
	return (tab);
}
