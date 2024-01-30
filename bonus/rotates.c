/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:25:19 by acomet            #+#    #+#             */
/*   Updated: 2023/01/11 20:03:42 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a_bonus(t_list **stack_a)
{
	t_list	*temp;
	t_list	*navig;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	navig = *stack_a;
	while (navig->next)
		navig = navig->next;
	navig->next = temp;
	navig->next->next = NULL;
}

void	rotate_b_bonus(t_list **stack_b)
{
	t_list	*temp;
	t_list	*navig;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	navig = *stack_b;
	while (navig->next)
		navig = navig->next;
	navig->next = temp;
	navig->next->next = NULL;
}

void	rotate_ab_bonus(t_list **stack_a, t_list **stack_b)
{
	rotate_a_bonus(stack_a);
	rotate_b_bonus(stack_b);
}
