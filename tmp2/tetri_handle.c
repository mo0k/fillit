#include "fillit.h"
#include "libft/libft.h"

t_hash	    *save_tetri(char **tetri, int xstart, int ystart)
{
    int	    i;
    int	    j;
    t_hash  *hashs;
    t_hash  *tmp;

    if (!(hashs = (t_hash *)malloc(sizeof(t_hash))))
        return (NULL);
    if (!(tmp = (t_hash *)malloc(sizeof(t_hash))))
        return (NULL);
    tmp = hashs;
    i = 0;
    while (tetri[ystart + i])
    {
	j = 0;
	while (tetri[ystart + i][xstart + j])
	{
	    if (tetri[ystart + i][xstart + j] == '#')
	    {
		tmp->x = i;
		tmp->y = j;
    		if (!(tmp->next = (t_hash *)malloc(sizeof(t_hash))))
		    return (NULL);
		tmp = tmp->next;
//		printf("%d %d \n", i, j);
	    }
	    j++;
	}
	i++;
    }
    free(tmp);
    return (hashs);
}

int	    locate_tetri(t_tetri *piece, char **tetri)
{
    int	    i;
    int	    j;
    int	    xstart;
    int	    ystart;

    i = 0;
    xstart = 4;
    ystart = -1;
    while (tetri[i])
    {
	j = 0;
	if (ystart < 0 && ft_strchr(tetri[i], '#'))
	    ystart = i;
	while (tetri[i][j] && tetri[i][j] != '#')
	    j++;
	while (tetri[i][j])
	{
	    if (j < xstart && tetri[i][j] == '#')
		xstart = j;
	    j++;
	}
	i++;
    }
    if (!(piece->hash = (t_hash *)malloc(sizeof(t_hash))))
	return (0);
    if (!(piece->hash = save_tetri(tetri, xstart, ystart)))
	return (0);
    return (1);
}

t_tetri	    *store_tetri(t_tetri *piece, char *buff)
{
    t_tetri	*tmp;
    char	letter;

    if (!(tmp = (t_tetri *)malloc(sizeof(t_tetri))))
	return (0);
    tmp = piece;
    letter = 'A';
    while (tmp->hash)
    {
	if (!(tmp->next = (t_tetri *)malloc(sizeof(t_tetri))))
	    return (0);
	tmp = tmp->next;
	letter++;
    }
//    printf("%s", buff);
    if (!locate_tetri(tmp, ft_strsplit(buff, '\n')))
       return (NULL);
    tmp->letter = letter;
    return (piece);
}
