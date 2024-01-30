#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	*big = "lorem ipsum dolor sit amet";
	char	*little = "ipsumm";
	size_t	len = 30;

	printf("%c\n", ft_strnstr(big, little, len));
	return (0);
}
