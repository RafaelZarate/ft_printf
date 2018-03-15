
#include "includes/ft_printf.h"

int	main(void)
{
	int i = 10;

	int n = ft_printf("%d\n", i);
	int n2 =printf("%d\n", i);

	printf("%d - %d", n, n2);
	return (0);
}