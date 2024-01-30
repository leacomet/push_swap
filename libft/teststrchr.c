#include "ft_strchr.c"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	s[] = "abcdefghijklmnopqrstuvwxyz";
	char	c = '\0';

	printf("%s\n", strchr(s, c));
	printf("%s\n", ft_strchr(s, c));
}
