#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s1 = "abcdefgh";
	char *s2 = "abccefgh";
	size_t				n = 7;

	printf("%d\n", memcmp(s1, s2, n));
	printf("%d\n", ft_memcmp(s1, s2, n));
}
