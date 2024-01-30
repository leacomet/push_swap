#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char *dst = NULL;
	char *src = "def";

	printf("%ld", ft_strlcat(dst, src, 0));
	printf("%s", dst);
	return (0);
}
