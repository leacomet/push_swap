/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:42:26 by acomet            #+#    #+#             */
/*   Updated: 2023/01/06 16:28:44 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_a(t_list **stack_a)
{
	t_list	*temp;
	t_list	*navig;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	if ((*stack_a)->next->next == NULL)
	{
		swap_a_without_write(stack_a);
		write(1, "rra\n", 4);
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
	write(1, "rra\n", 4);
}

void	reverse_b(t_list **stack_b)
{
	t_list	*temp;
	t_list	*navig;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	if ((*stack_b)->next->next == NULL)
	{
		swap_b_without_write(stack_b);
		write(1, "rrb\n", 4);
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
	write(1, "rrb\n", 4);
}

void	reverse_a_without_write(t_list **stack_a)
{
	t_list	*temp;
	t_list	*navig;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	if (!(*stack_a)->next->next)
	{
		swap_a_without_write(stack_a);
		return ;
	}
	navig = *stack_a;
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

void	reverse_b_without_write(t_list **stack_b)
{
	t_list	*temp;
	t_list	*navig;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	if (!(*stack_b)->next->next)
	{
		swap_b_without_write(stack_b);
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

void	reverse_ab(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a) && ((*stack_a)->next))
	{
		if ((*stack_b) && ((*stack_b)->next))
		{
			reverse_a_without_write(stack_a);
			reverse_b_without_write(stack_b);
		}
		else
			reverse_a_without_write(stack_a);
	}
	else if ((*stack_b) && ((*stack_b)->next))
		reverse_b_without_write(stack_b);
	else
		return ;
	write(1, "rrr\n", 4);
}
