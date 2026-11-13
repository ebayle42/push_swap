static void	run_aglo(int mode, //stack *a, stack *b, ..)
{
	if (count == 1)
		adaptive_sort(a, b,  );
	if (count == 2)
		complex_sort(a, b,  );
	if (count == 3)
		medium_sort(a, b,  );
	if (count == 4)
		simple_sort(a, b,  );
}

void	check_algo(int mode,//stack *a, stack *b, ..)
{
	run_algo(mode % 10, a, b, ..);
	if (mode > 10)
		ft_printf_bench(mode, ..);
}
