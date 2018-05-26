#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	(void)ac;
	ft_putnbr_base(atoi(av[1]), av[2]);
	return (0);
}
