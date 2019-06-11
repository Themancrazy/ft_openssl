#include <ft_ssl.h>

void			send_error(char *error)
{
	ft_putstr(error);
	ft_putchar('\n');
	free(error);
	exit(-1);
}
