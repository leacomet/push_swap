#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	unsigned const char	s[] = "abcdefgh";
	int			c = 'd';
	size_t		n = 5;
//	unsigned char str;

	printf("%s\n", memchr(s, c, n));
//	printf("%s\n", ft_memchr(s, c, n));
//	str = (unsigned char *)(memchr(s, c, n));
//	printf("%s\n", str);
}
