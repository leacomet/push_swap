/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:23:37 by acomet            #+#    #+#             */
/*   Updated: 2022/10/04 19:06:28 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
		while ((s[i] != c) && (s[i] != '\0'))
		{
			i++;
			if (s[i] == c || s[i] == '\0')
				wordcount++;
		}
	}
	if ((s[0] != '\0') && (s[i - 1] == c))
		wordcount++;
	return (wordcount);
}

int	main(void)
{
	char	*s = 0;
	char	c = 0;
	char **str;
	int		i;
	int		wordcount;

	i = 0;
	wordcount = ft_wordcount(s, c);
	str = ft_split(s, c);
	while (i < wordcount)
	{
		printf("%s\n", str[i]);
		i++;
	}
	free(str);
}

