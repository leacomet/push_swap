/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:41:44 by acomet            #+#    #+#             */
/*   Updated: 2023/01/09 16:10:24 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	total_is_not_sorted(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;

	if (*stack_b)
		return (1);
	if (!*stack_a)
		return (1);
	temp_a = *stack_a;
	while (temp_a->next)
	{
		if (temp_a->content > temp_a->next->content)
			return (1);
		temp_a = temp_a->next;
	}
	return (0);
}

int	is_not_sorted(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	is_not_upside_down(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}
