
#include "includes/ft_printf.h"

int	main(void)
{

	// int n = printf("%+04ld\n", 4294959296);
	// printf("PR: %d\n", n);

	// int n3 = ft_printf("%+04ld\n", 4294959296);
	// printf("FT: %d\n", n3);

	// int n8 = printf("%+04li\n", 4294959296);
	// printf("PR: %d\n", n8);

	// int n7 = ft_printf("%+04li\n", 4294959296);
	// printf("FT: %d\n", n7);

	int n6 = printf("\\n");
	printf("PR: %d\n", n6);

	int n4 = ft_printf("\\n");
	printf("FT: %d\n", n4);
	while (1)
		n4++;
	return (0);
}
