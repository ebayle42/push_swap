static void	run_algo(int mode, //stack *a, stack *b, ..)
{
	if (mode == 1)
		adaptive_sort(a, b,  );
	else if (mode == 2)
		complex_sort(a, b,  );
	else if (mode == 3)
		medium_sort(a, b,  );
	else if (mode == 4)
		simple_sort(a, b,  );
}

void	check_algo(int mode,//stack *a, stack *b, ..)
{
	run_algo(mode % 10, a, b, ..);
	if (mode > 10)
		ft_printf_bench(mode, ..);
}
