
#include "includes/ft_printf.h"

int	main(void)
{
	
//	int i = 4567;

	int n = printf("%010%LOL%i\n", 10);
	printf("PR: %d\n", n);

	int n2 = ft_printf("%010%LOL%i\n", 10);
	printf("FT: %d\n", n2);

	return (0);
}
