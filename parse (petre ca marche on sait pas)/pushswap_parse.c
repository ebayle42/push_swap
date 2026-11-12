#include <stdarg.h>
#include <unistd.h>
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

static int	check(char **argv, int i, int cc)
{
	int	count;
	
	count = 0;
	if (ft_strcmp(argv[cc], "Test") == 0)
		return (count = ft);
	if (ft_strcmp(argv[cc], "Test2") == 0)
		
	return (-2);
}
int	push_swap(char **argv, int argc)
{
	int	i;
	int	cc;
	int	test;

	cc = 1;
	test = 0;
	if (argc == 1)
		return(-1);//lancer en adaptatif
	while (cc < argc)
	{
		i = 2;
		while (argv[cc][i])
		{
			if (argv[cc][i - 2] == '-' && argv[cc][i - 1] == '-')
				{
					test = check(argv, i, cc);
					break ;
				}
				else 
				{
					write(1, "Error\n", 6);
					break ;
				}
			i++;
		}
		cc++;
	}
	return(test);
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
