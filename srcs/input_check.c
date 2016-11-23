/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:17:54 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/23 15:49:27 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int			tetri_isvalid(char **tetri)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 1;
	while (tetri[++i])
	{
		j = -1;
		while (tetri[i][++j])
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
		}
	}
	if (count < 4)
		return (0);
	return (1);
}

int			check_tetri(char *buff)
{
	int	len;
	int	height;
	int	hash;
	int	i;

	init(&len, &height, &hash, &i);
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
	height -= (buff[i - 1] == '\n' && len == 0 && i != 20) ? 1 : 0;
	if (height != 4 || hash != 4)
		return (0);
	return (tetri_isvalid(ft_strsplit(buff, '\n')));
}

t_tetri		*get_pieces(int fd, t_tetri *pieces, char *buff, int *nbpieces)
{
	t_tetri	*tmp;
	int		nbcheck;
	char	letter;
	int		ret;

	if (!(tmp = (t_tetri *)ft_memalloc(sizeof(t_tetri))))
		return (NULL);
	*nbpieces = 0;
	nbcheck = 0;
	letter = 'A';
	tmp = pieces;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		nbcheck += (ret == 21) ? 1 : 0;
		if (!(check_tetri(buff)) || ret < 20 || ++*nbpieces > 26)
			return (NULL);
		if (!(locate_tetri(tmp, letter++, ft_strsplit(buff, '\n'))))
			return (NULL);
		if (!(tmp->next = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		tmp = tmp->next;
	}
	if (*nbpieces == 0 || nbcheck == *nbpieces)
		return (NULL);
	return (pieces);
}
