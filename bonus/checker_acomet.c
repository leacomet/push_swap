/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_acomet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:28:55 by acomet            #+#    #+#             */
/*   Updated: 2023/01/12 15:54:59 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_reverse(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "rra\n", 4))
		reverse_a_bonus(stack_a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		reverse_b_bonus(stack_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
	{
		reverse_a_bonus(stack_a);
		reverse_b_bonus(stack_b);
	}
	else
	{
		write (2, "Error\n", 6);
		free(str);
		str = get_next_line(0, 1);
		return (0);
	}
	return (1);
}

int	do_instruction(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap_a_bonus(stack_a);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap_b_bonus(stack_b);
	else if (!ft_strncmp(str, "ss\n", 3))
	{
		swap_a_bonus(stack_a);
		swap_b_bonus(stack_b);
	}
	else if (!ft_strncmp(str, "pa\n", 3))
		push_a_bonus(stack_a, stack_b);
	else if (!ft_strncmp(str, "pb\n", 3))
		push_b_bonus(stack_a, stack_b);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate_a_bonus(stack_a);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate_b_bonus(stack_b);
	else if (!ft_strncmp(str, "rr\n", 3))
	{
		rotate_a_bonus(stack_a);
		rotate_b_bonus(stack_b);
	}
	else if (!do_reverse(stack_a, stack_b, str))
		return (0);
	return (1);
}

int	get_instructions(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0, 0);
	while (str)
	{
		if (!do_instruction(stack_a, stack_b, str))
			return (0);
		free(str);
		str = get_next_line(0, 0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**grid;

	if (argc == 1 || check_error_empty_and_spaces(argv))
		return (1);
	grid = NULL;
	grid = create_grid(argc, argv, grid);
	check_error_nodigit_max_min_int(grid);
	stack_a = NULL;
	stack_a = create_stack_a_and_check_duplicate(grid, stack_a);
	free_grid(grid);
	stack_b = NULL;
	if (get_instructions(&stack_a, &stack_b))
	{
		if (!total_is_not_sorted(&stack_a, &stack_b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
