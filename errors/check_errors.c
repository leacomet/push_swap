/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:54:16 by acomet            #+#    #+#             */
/*   Updated: 2023/01/12 17:02:36 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_error_empty_and_spaces(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				j++;
			else
				break ;
		}
		if (argv[i][j] == '\0')
			return (write(2, "Error\n", 6));
		i++;
	}
	return (0);
}

int	check_error_nodigit_max_min_int(char **grid)
{
	int		i;

	i = 0;
	while (grid[i])
	{
		if (grid[i][0] != '+' && grid[i][0] != '-' && !ft_isdigit(grid[i][0]))
		{
			write(2, "Error\n", 6);
			free_grid(grid);
			exit (1);
		}
		if (atol(grid[i]) == 7177277377)
		{
			write(2, "Error\n", 6);
			free_grid(grid);
			exit (1);
		}
		i++;
	}
	return (0);
}

int	check_duplicate(char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = i + 1;
		while (grid[j])
		{
			if (atoi(grid[i]) == atoi(grid[j]))
				return (write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicate2(t_list *list)
{
	t_list	*next_one;

	while (list)
	{
		next_one = list->next;
		while (next_one)
		{
			if (list->content == next_one->content)
				return (write(2, "Error\n", 6));
			next_one = next_one->next;
		}
		list = list->next;
	}
	return (0);
}
