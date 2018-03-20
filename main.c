
#include "includes/ft_printf.h"

int	main(void)
{

	int n = printf("%+04d\n", 42);
	printf("PR: %d\n", n);

	int n3 = ft_printf("%0+4d\n", 42);
	printf("FT: %d\n", n3);

	int n2 = ft_printf("%+04d\n", 42);
	printf("FT: %d\n", n2);

	return (0);
}
