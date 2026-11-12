#include <stdarg.h>
#include <unistd.h>

static int	check2(int count)
{
	if (count == 1)
	if (count == 2)
	if (count == 3)
	if (count == 4)
	
}
static int ft_strcmp(char *argv, char *cmp)
{
	int i;
	
	i = 0;
	while (cmp[i])
	{
		if (argv[i + 2] != cmp[i])
			return (-1);
		i++;
	}
	return (0);
}

static int	check(char **argv, int cc, int count)
{
	if (ft_strcmp(argv[cc], "adaptive") == 0)
		count += 1;
	else if (ft_strcmp(argv[cc], "complex") == 0)
		count += 2;	
	else if (ft_strcmp(argv[cc], "medium") == 0)
		count += 3;	
	else if (ft_strcmp(argv[cc], "simple") == 0)
		count += 4;
	else if (ft_strcmp(argv[cc], "bench") == 0)
		count += 10;
	return (count);
}
int	push_swap(char **argv, int argc)
{
	int	i;
	int	cc;
	int	count;

	cc = 1;
	count = 0;
	if (argc == 1)
		return(-1);//lancer en adaptatif
	if (argc > 3)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	while (cc < argc)
	{
		i = 2;
		if (argv[cc][i - 2] == '-' && argv[cc][i - 1] == '-')
				count = check(argv, cc, count);
	 cc++;
	}
	check2(count);
	return(count);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	printf("[%d]\n", push_swap(argv, argc));	
	return (0);
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
