/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:48:54 by acomet            #+#    #+#             */
/*   Updated: 2022/09/27 13:37:58 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c < 'A' || c > 'z')
		return (0);
	if (c > 'Z' && c < 'a')
		return (0);
	return (1);
}