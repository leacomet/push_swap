#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char const	*s = "42";
	unsigned int start = 0;
	size_t len = 0;

	printf("%s\n", ft_substr(s, start, len));
	return (0);
}

