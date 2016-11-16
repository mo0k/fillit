#include "fillit.h"
#include "libft/libft.h"

int	    save_tetri(t_tetri *piece, char **tetri, int xstart, int ystart)
{
    int	    i;
    int	    j;

    i = 0;
    while (tetri[ystart + i])
    {
	j = 0;
	while (tetri[ystart + i][xstart + j])
	{
	    if (tetri[ystart + i][xstart + j] == '#')
	    
	    j++;
	}
	i++;
    }
    return (1);
}

int	    locate_tetri(t_tetri *piece, char **tetri)
{
    t_hash  *hash;
    int	    i;
    int	    j;
    int	    xstart;
    int	    ystart;

    if (!(hash = (t_hash *)malloc(sizeof(hash))))
	return (0);
    i = 0;
    while (tetri[i])
    {
	j = 0;
	if(ft_strchr(tetri[i], '#') && !ystart)
	    ystart = i;
	while (tetri[i][j] && tetri[i][j] != '#')
	    j++;
	if (j < xstart)
	    xstart = j;
    }
    return (save_tetri(piece, tetri, xstart, ystart));
}

t_tetri	*store_tetri(t_tetri *piece, char *buff)
{
    t_tetri	*tmp;

    if (!(tmp = (t_tetri *)malloc(sizeof(t_tetri))))
	return (0);
    tmp = piece;
    while (tmp->next)
	tmp = tmp->next;
   if (!locate_tetri(piece, ft_strsplit(buff, '\n')))
       return (NULL);
    return (piece);
}
