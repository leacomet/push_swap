/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_modified.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:21:17 by acomet            #+#    #+#             */
/*   Updated: 2022/12/29 18:21:18 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*strjoin_with_space(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (str == NULL)
		free_str_exit(s1);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = ' ';
	i++;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

long	atol(const char *str)
{
	long	nb;
	long	neg;
	int		i;

	nb = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i++] == '-')
			neg *= -1;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		nb *= 10;
		nb += (str[i++] - '0');
		if ((nb > 2147483648) || (nb == 2147483648 && neg > 0))
			return (7177277377);
	}
	if (str[i] != '\0')
		return (7177277377);
	return (nb * neg);
}
