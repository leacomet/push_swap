#include "libft.h"


int main(void)
{
	char nptr[] = "     \n  2147483646544365465346634639";
	printf("%d\n", ft_atoi(nptr));
	printf("%d\n", atoi(nptr));
	return(0);
}
