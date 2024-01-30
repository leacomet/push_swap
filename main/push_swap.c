#include "../push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**grid;
	int		nbr_count;

	if (check_error_empty_and_spaces(argv))
		return (1);
	grid = NULL;
	grid = create_grid(argc, argv, grid);
	check_error_nodigit_max_min_int(grid);
	stack_a = NULL;
	stack_a = create_stack_a_and_check_duplicate(grid, stack_a);
	free_grid(grid);
	stack_b = NULL;
	nbr_count = count_of_number(&stack_a);
	normalized(&stack_a, nbr_count);
	if (is_not_sorted(&stack_a))
		sort_algorithm(&stack_a, &stack_b, nbr_count);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	push_swap(argc, argv);
}
