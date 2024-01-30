/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:26:13 by acomet            #+#    #+#             */
/*   Updated: 2023/02/23 14:43:42 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	better_move(t_list **stack_a, t_list **stack_b, int target, int limit)
{
	int	i;

	i = is_rotate_better(stack_b, target, limit);
	if (i)
		target -= if_rotate_better(stack_a, stack_b, target, i);
	else
	{
		i = is_reverse_better(stack_b, target);
		target -= if_reverse_better(stack_a, stack_b, target, i - 1);
	}
	return (target);
}

static void	return_to_a(t_list **stack_a, t_list **stack_b, int chunk)
{
	int	target;
	int	limit;
	int	nbr_count;

	nbr_count = count_of_number(stack_b);
	target = nbr_count;
	limit = target / chunk * chunk;
	while (*stack_b)
	{
		if (limit == target)
			limit -= nbr_count / chunk;
		if ((*stack_b)->content == target)
		{
			push_a(stack_a, stack_b);
			target --;
		}
		else
			target = better_move(stack_a, stack_b, target, limit);
	}
}

static void	wings(t_list **stack_a, t_list **stack_b, int nbr_count, int chunk)
{
	int	i;
	int	chunk_max;
	int	pivot;

	i = 0;
	chunk_max = 0;
	pivot = (nbr_count / chunk) / 2;
	while (*stack_a)
	{
		chunk_max += nbr_count / chunk;
		while (i < chunk_max && (*stack_a))
		{
			if ((*stack_a)->content <= chunk_max)
			{
				push_b(stack_a, stack_b);
				if ((*stack_b)->content > pivot)
					rotate_b(stack_b);
				i++;
			}
			else
				rotate_a(stack_a);
		}
		pivot += nbr_count / chunk;
	}
}

static int	define_chunk_number(int nbr_count)
{
	if (nbr_count <= 50)
		return (2);
	else if (nbr_count <= 100)
		return (3);
	else if (nbr_count <= 200)
		return (5);
	else if (nbr_count <= 300)
		return (6);
	else if (nbr_count <= 400)
		return (7);
	else if (nbr_count <= 500)
		return (8);
	else if (nbr_count <= 750)
		return (9);
	else
		return (11);
}

void	sort_algorithm(t_list **stack_a, t_list **stack_b, int nbr_count)
{
	int	i;
	int	chunk;

	i = 0;
	sort_little_number(stack_a, stack_b, nbr_count);
	if (total_is_not_sorted(stack_a, stack_b))
	{
		chunk = define_chunk_number(nbr_count);
		wings(stack_a, stack_b, nbr_count, chunk);
		return_to_a(stack_a, stack_b, chunk);
	}
}
