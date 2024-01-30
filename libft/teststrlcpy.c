//#include "ft_strlcpy.c"
#include "ft_strlen.c"
#include <stdlib.h>
#include <stdio.h>
#include <bsd/string.h>


int	main(void)
{
	char		dst[] = "123456789";
//	char		*dst1 = "123456789";
	const char	src[] = "abcdefghijklmnopqrstuvwxyz";
	int		size = 0;

	printf("vf : %ld\n", ft_strlen(dst));
//	printf("cf : %ld\n", ft_strlen(dst1));
	printf("vf : %s\n", dst);
//	printf("cf : %s\n", dst1);
	printf("vrai fonction : %ld\n", strlcpy(dst, src, size));
//	printf("custom fonction : %ld\n", ft_strlcpy(dst1, src, size);
	printf("vf : %ld\n", ft_strlen(dst));
	printf("vf : %s\n", dst);
//	printf("cf : %ld\n", ft_strlen(dst1));
//	printf("cf : %s\n", dst1);
}
