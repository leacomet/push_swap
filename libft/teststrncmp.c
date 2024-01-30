#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char	*s1 = "abcdefgh";
	char	*s2 = "abcdéfgh";
	unsigned int n = 9;

	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));
}
