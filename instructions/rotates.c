/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:25:19 by acomet            #+#    #+#             */
/*   Updated: 2023/01/06 16:25:28 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_list **stack_a)
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
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b)
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
	write(1, "rb\n", 3);
}

void	rotate_a_without_write(t_list **stack_a)
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

void	rotate_b_without_write(t_list **stack_b)
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

void	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a) && ((*stack_a)->next))
	{
		if ((*stack_b) && ((*stack_b)->next))
		{
			rotate_a_without_write(stack_a);
			rotate_b_without_write(stack_b);
		}
		else
			rotate_a_without_write(stack_a);
	}
	else if ((*stack_b) && ((*stack_b)->next))
		rotate_b_without_write(stack_b);
	else
		return ;
	write(1, "rr\n", 3);
}
