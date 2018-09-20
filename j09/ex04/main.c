#include <stdio.h>

char	*ft_rot42(char *str);

int		main(int ac, char **av)
{
	(void)ac;
	printf("%s\n", ft_rot42(av[1]));
	return (0);
}
