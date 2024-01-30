#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int	n = 0;
	char	*str;

//	printf("%s\n", ft_itoa(n));
	str = ft_itoa(n);
	printf("%s\n", str);
	free(str);
	return (0);
}
