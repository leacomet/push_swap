/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:45 by acomet            #+#    #+#             */
/*   Updated: 2022/12/07 22:50:41 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_stack_a_and_check_duplicate(char **grid, t_list *stack_a)
{
	int	i;

	i = 0;
	while (i < 20 && grid[i])
		i++;
	if (i < 20)
	{
		if (check_duplicate(grid))
			free_grid_exit(grid);
		stack_a = create_stack_a(grid);
	}
	else
	{
		stack_a = create_stack_a(grid);
		if (check_duplicate2(stack_a))
		{
			ft_lstclear(&stack_a);
			free_grid_exit(grid);
		}
	}
	return (stack_a);
}
