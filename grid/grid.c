/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:31:07 by acomet            #+#    #+#             */
/*   Updated: 2022/12/07 22:17:33 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**create_grid(int argc, char **argv, char **grid)
{
	int		i;
	char	*str;

	i = 1;
	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	i = 1;
	while (i < argc)
	{
		str = strjoin_with_space(str, argv[i]);
		i++;
	}
	if (str == NULL)
		free_str_exit(str);
	grid = ft_split(str, ' ');
	free(str);
	if (grid == NULL)
	{
		free_grid(grid);
		free_str_exit(str);
	}
	return (grid);
}
