#include "fillit.h"
#include "libft/libft.h"

int	    tetri_isvalid(char **tetri)
{
    int	    i;
    int	    j;
    int	    count;

    i = 0;
    count = 1;
    while (tetri[i])
    {
	j = 0;
	while (tetri[i][j])
	{
	    if (tetri[i][j] == '#')
	    {
		if (i < 3 && count < 4)
		    if (tetri[i + 1][j] == '#')
			count++;
		if (j < 3 && count < 4)
		    if (tetri[i][j + 1] == '#')
			count++;
	    }
	    j++;
	}
	i++;
    }
    if (count < 4)
	return (0);
    return (1);
}

int	    check_tetri(char *buff)
{
	int	len;
	int	height;
	int	hash;
	int	i;

	len = 0;
	height = 0;
	hash = 0;
	i = 0;
//	init(&len, &height, &hash, &i);
//	printf("%s", buff);
	while (buff[i])
	{
	    if (buff[i] == '#')
		hash++;
	    if (buff[i] == '.' || buff[i] == '#')
		len++;
	    if (buff[i] == '\n')
	    {
		if ((len != 4 && i < 18) || i > 21)
		    return (0);
		height++;
		len = 0;
	    }
	    i++;
	}
	if (buff[i - 1] == '\n' && len == 0)
	    height--;
	if (height != 4 || hash != 4)
	    return (0);
//	printf("%s", buff);
//	printf("%s \n %d %d \n", buff, height, len);
	return (tetri_isvalid(ft_strsplit(buff, '\n')));
}

t_tetri		*get_pieces(char *av)
{
	t_tetri		*pieces;
	char		*buff;
	unsigned int	nbcheck;
	unsigned int	i;
	int		fd;
	int		ret;

	if (!(fd = open(av, O_RDONLY)))
	    return (NULL);
	pieces = (t_tetri *)ft_memalloc(sizeof(t_tetri));
	buff = (char *)ft_memalloc(BUFF_SIZE + 1);
	i = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
	    buff[ret] == 0;
	    if (ret == 21)
		nbcheck++;
	    if (!(check_tetri(buff)) || ret < 20 || i > 26)
		return (NULL);
//	    pieces = store_tetri(pieces, buff);
	    i++;
	}
	if (i == 0 || nbcheck == i)
	    return(NULL);
	return (pieces);
}
