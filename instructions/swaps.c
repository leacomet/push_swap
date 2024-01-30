/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:35:29 by acomet            #+#    #+#             */
/*   Updated: 2022/12/29 18:07:12 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_list **stack_a)
{
	int	temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = temp;
	write (1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	int	temp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = temp;
	write (1, "sb\n", 3);
}

void	swap_a_without_write(t_list **stack_a)
{
	int	temp;

	temp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = temp;
}

void	swap_b_without_write(t_list **stack_b)
{
	int	temp;

	temp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = temp;
}

void	swap_ab(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a) && ((*stack_a)->next))
	{
		if ((*stack_b) && ((*stack_b)->next))
		{
			swap_a_without_write(stack_a);
			swap_b_without_write(stack_b);
		}
		else
			swap_a_without_write(stack_a);
	}
	else if ((*stack_b) && ((*stack_b)->next))
		swap_b_without_write(stack_b);
	else
		return ;
	write(1, "ss\n", 3);
}
