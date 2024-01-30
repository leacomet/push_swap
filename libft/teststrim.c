#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	s1[] = "acbbcPatrick va a la piscineaa";
	char	set[] = "abc";

	printf("%s\n", ft_strtrim(s1, set));
}
