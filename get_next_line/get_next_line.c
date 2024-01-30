/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:05:34 by acomet            #+#    #+#             */
/*   Updated: 2023/01/12 15:55:58 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_beyond_line(char *str)
{
	char	*temp;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	temp = NULL;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	j = 0;
	while (str[i + j] != '\0')
		j++;
	if (j != 0)
	{
		temp = malloc(sizeof(char) * (j + 1));
		if (temp == NULL)
			return (NULL);
		gnl_strcpy(temp, str + i + 1);
	}
	free (str);
	return (temp);
}

static char	*ft_get_final_str(char *str)
{
	char	*final_str;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	final_str = malloc(sizeof(char) * (i + 1));
	if (final_str == NULL)
		return (NULL);
	gnl_strlcpy(final_str, str, i + 1);
	return (final_str);
}

static char	*ft_the_next_line(int fd, char *str, int i)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	while ((gnl_strchr(buffer) == -1) && (i > 0))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = gnl_strjoin(str, buffer);
	}
	free(buffer);
	if (i == 0 && str[0] == '\0')
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*get_next_line(int fd, int error)
{
	static char	*str = NULL;
	char		*final_str;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (error)
	{
		if (str)
			free(str);
		return (NULL);
	}
	i = 1;
	str = ft_the_next_line(fd, str, i);
	final_str = ft_get_final_str(str);
	str = ft_get_beyond_line(str);
	return (final_str);
}
