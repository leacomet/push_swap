/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalized.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:06:07 by acomet            #+#    #+#             */
/*   Updated: 2023/02/23 15:31:44 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_better_number_to_stack_a(t_list **stack_a)
{
	t_list	*lst;

	lst = (*stack_a);
	while (lst)
	{
		lst->content += 2147483649;
		lst = lst->next;
	}
}

void	normalized(t_list **stack_a, int nbr_count)
{
	int		i;
	int		end;
	int		temp;
	t_list	*lst;
	t_list	*next_min;

	i = -2147483648;
	end = i + nbr_count;
	while (i < end)
	{
		i += 1;
		lst = *stack_a;
		temp = 2147483647;
		while (lst)
		{
			if ((lst->content <= temp) && (lst->content >= i - 1))
			{
				next_min = lst;
				temp = lst->content;
			}
			lst = lst->next;
		}
		next_min->content = i - 1;
	}
	set_better_number_to_stack_a(stack_a);
}
