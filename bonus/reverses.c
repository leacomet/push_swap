/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:42:26 by acomet            #+#    #+#             */
/*   Updated: 2023/01/11 20:09:55 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_a_bonus(t_list **stack_a)
{
	t_list	*temp;
	t_list	*navig;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	if ((*stack_a)->next->next == NULL)
	{
		swap_a_bonus(stack_a);
		return ;
	}
	navig = ((*stack_a)->next);
	while (navig->next->next)
		navig = navig->next;
	temp = navig->next;
	navig->next = NULL;
	navig = temp;
	temp = *stack_a;
	*stack_a = navig;
	(*stack_a)->next = temp;
}

void	reverse_b_bonus(t_list **stack_b)
{
	t_list	*temp;
	t_list	*navig;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	if ((*stack_b)->next->next == NULL)
	{
		swap_b_bonus(stack_b);
		return ;
	}
	navig = *stack_b;
	navig = ((*stack_b)->next);
	while (navig->next->next)
		navig = navig->next;
	temp = navig->next;
	navig->next = NULL;
	navig = temp;
	temp = *stack_b;
	*stack_b = navig;
	(*stack_b)->next = temp;
}

void	reverse_ab_bonus(t_list **stack_a, t_list **stack_b)
{
	reverse_a_bonus(stack_a);
	reverse_b_bonus(stack_b);
}
