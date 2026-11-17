#include "push_swap.h"

static void	run_algo(int mode, t_ps *ps)
{
	if (mode == 1)
		quick_sort(ps);
	else if (mode == 2)
		quick_sort(ps);
	else if (mode == 3)
		range_sort(ps);
	else if (mode == 4)
		minmax_sort(ps);
}

void	check_algo(int mode, t_ps *ps)
{
	run_algo(mode % 10, ps);
}
