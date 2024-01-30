/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:39:49 by acomet            #+#    #+#             */
/*   Updated: 2023/01/12 16:08:12 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

t_list	*create_stack_a(char **grid)
{
	t_list	*list;
	t_list	*first_position;
	int		i;

	list = ft_lstnew(atoi(grid[0]));
	if (!list)
		free_grid_exit(grid);
	first_position = list;
	i = 1;
	while (grid[i])
	{
		list->next = ft_lstnew(atoi(grid[i++]));
		if (!list->next)
		{
			ft_lstclear(&first_position);
			free_grid_exit(grid);
		}
		list = list->next;
	}
	return (first_position);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}
