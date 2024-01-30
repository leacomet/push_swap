#include "ft_memcpy.c"
#include <string.h>
#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	unsigned char		dest[100] = "";
	unsigned char    	dest1[100] = "";
	unsigned const char	src[100] = "10";
	size_t	n = 0;

	printf("%p\n", memcpy(dest1, src, n));
	printf("%s\n", dest1);
	printf("%p\n", ft_memcpy(dest, src, n));
	printf("%s\n", dest);
}
