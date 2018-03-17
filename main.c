
#include "includes/ft_printf.h"

int	main(void)
{
	
//	int i = 4567;

	int n = printf("%%");
	int n2 = ft_printf("%");

	printf("PR: %d, FT: %d", n ,n2);

	return (0);
}
