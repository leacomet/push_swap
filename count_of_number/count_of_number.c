/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:46:55 by acomet            #+#    #+#             */
/*   Updated: 2022/12/17 12:14:49 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_of_number(t_list **lst)
{
	t_list	*temp;
	int		nbr_count;

	nbr_count = 0;
	temp = *lst;
	while (temp)
	{
		nbr_count++;
		temp = temp->next;
	}
	return (nbr_count);
}
