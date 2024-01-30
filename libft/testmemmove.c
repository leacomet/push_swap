#include "libft.h"
#include "ft_memmove.c"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	unsigned char	dest[] = "abcdefghijkl";
	unsigned char	dest1[] = "abcdefghijkl";
	unsigned const char	src[] = "123456789";
	unsigned const char	src1[] = "123456789";
	size_t				n = 7;

	printf("%p\n", memmove(dest1, src1, n));
	printf("%s\n", dest1);
	printf("%p\n", ft_memmove(dest, src, n));
	printf("%s\n", dest);
}
