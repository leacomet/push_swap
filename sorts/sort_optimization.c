/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_optimization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:00:00 by acomet            #+#    #+#             */
/*   Updated: 2023/01/08 18:41:36 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_rotate_better_at_end(t_list **stack_b, int target, int limit, int i)
{
	t_list	*temp;
	int		j;

	temp = *stack_b;
	limit = target / 2;
	j = 0;
	while (j < limit + 1)
	{
		if (temp->content == target - 1)
			i += is_rotate_better(stack_b, target - 1, limit);
		else if (temp->content == target)
			return (i);
		temp = temp->next;
		j++;
	}
	return (0);
}

int	is_rotate_better(t_list **stack_b, int target, int limit)
{
	t_list	*temp;
	int		i;

	i = 1;
	if (limit == 0)
		return (is_rotate_better_at_end(stack_b, target, limit, i));
	temp = *stack_b;
	while (temp->content > limit)
	{
		if (temp->content == target - 1)
			i += is_rotate_better(stack_b, target - 1, limit);
		else if (temp->content == target)
			return (i);
		temp = temp->next;
	}
	return (0);
}

int	if_rotate_better(t_list **stack_a, t_list **stack_b, int target, int i)
{
	int	j;

	j = i - 1;
	while ((*stack_b)->content != target)
	{
		while ((*stack_b)->content != (target - i + 1))
			rotate_b(stack_b);
		if ((*stack_b)->content != target)
		{
			push_a(stack_a, stack_b);
			if ((*stack_a)->content != target - 1)
				rotate_a(stack_a);
			i--;
		}
	}
	push_a(stack_a, stack_b);
	i = j + 1;
	if (j)
		swap_a(stack_a);
	while (j > 1)
	{
		reverse_a(stack_a);
		j--;
	}
	return (i);
}

int	is_reverse_better(t_list **stack_b, int target)
{
	t_list	*temp;
	int		i;

	i = 1;
	temp = *stack_b;
	while (temp && temp->content != target)
		temp = temp->next;
	if (temp)
		i += is_reverse_better(&temp, target - 1);
	return (i);
}

int	if_reverse_better(t_list **stack_a, t_list **stack_b, int target, int i)
{
	int	j;

	j = i - 1;
	while ((*stack_b)->content != target)
	{
		while ((*stack_b)->content != (target - i + 1))
			reverse_b(stack_b);
		if ((*stack_b)->content != target)
		{
			push_a(stack_a, stack_b);
			if ((*stack_a)->content != target - 1)
				rotate_a(stack_a);
			i--;
		}
	}
	push_a(stack_a, stack_b);
	i = j + 1;
	if (j)
		swap_a(stack_a);
	while (j > 1)
	{
		reverse_a(stack_a);
		j--;
	}
	return (i);
}
