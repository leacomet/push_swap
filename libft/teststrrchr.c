/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teststrrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:13:08 by acomet            #+#    #+#             */
/*   Updated: 2022/09/30 19:19:45 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	s[] = "abcdefghijklmnaopqrstuvwxyz";
	char	c = 'a';

	printf("%s\n", strrchr(s, c));
	printf("%s\n", ft_strrchr(s, c));
}

