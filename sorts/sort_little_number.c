/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:42:35 by acomet            #+#    #+#             */
/*   Updated: 2023/01/04 17:25:03 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_list **stack_a)
{
	if ((*stack_a)->content < ((*stack_a)->next->content)
		&& ((*stack_a)->content < (*stack_a)->next->next->content))
	{
		reverse_a(stack_a);
		swap_a(stack_a);
	}
	else if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->content < (*stack_a)->next->next->content))
		swap_a(stack_a);
	else if (((*stack_a)->content < (*stack_a)->next->content)
		&& ((*stack_a)->next->content > (*stack_a)->next->next->content))
		reverse_a(stack_a);
	else if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->next->content > (*stack_a)->next->next->content))
	{
		swap_a(stack_a);
		reverse_a(stack_a);
	}
	else if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->next->content < (*stack_a)->next->next->content))
		rotate_a(stack_a);
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	while (count_of_number(stack_b) < 2)
	{
		if ((*stack_a)->content == 1 || ((*stack_a)->content == 2))
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	if (is_not_sorted(stack_a))
		sort_three(stack_a);
	if ((*stack_b)->content < (*stack_b)->next->content)
		swap_b(stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_little_number(t_list **stack_a, t_list **stack_b, int nbr_count)
{
	int	i;

	(void)stack_b;
	i = 0;
	if (nbr_count == 2)
		swap_a(stack_a);
	else if (nbr_count == 3)
		sort_three(stack_a);
	else if (nbr_count == 5)
		sort_five(stack_a, stack_b);
}
