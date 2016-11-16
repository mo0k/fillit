#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, (unsigned char *)(&c), 1);
}

void		ft_putstr(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
