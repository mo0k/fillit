/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:18:28 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/23 15:07:23 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_hash		*save_hash(t_hash *hash, char letter, int i, int j)
{
	hash->x = i;
	hash->y = j;
	hash->letter = letter;
	if (!(hash->next = (t_hash *)malloc(sizeof(t_hash))))
		return (NULL);
	hash = hash->next;
	return (hash);
}

t_hash		*save_tetri(char **tetri, char letter, int xstart, int ystart)
{
	int		i;
	int		j;
	t_hash	*hashs;
	t_hash	*tmp;

	if (!(hashs = (t_hash *)malloc(sizeof(t_hash))))
		return (NULL);
	if (!(tmp = (t_hash *)malloc(sizeof(t_hash))))
		return (NULL);
	tmp = hashs;
	i = -1;
	while (tetri[ystart + ++i])
	{
		j = -1;
		while (tetri[ystart + i][xstart + ++j])
		{
			if (tetri[ystart + i][xstart + j] == '#')
				tmp = save_hash(tmp, letter, i, j);
		}
	}
	tmp = NULL;
	free(tmp);
	return (hashs);
}

int			locate_tetri(t_tetri *piece, char letter, char **tetri)
{
	int		i;
	int		j;
	int		xstart;
	int		ystart;

	i = -1;
	xstart = 4;
	ystart = -1;
	while (tetri[++i])
	{
		j = 0;
		if (ystart < 0 && ft_strchr(tetri[i], '#'))
			ystart = i;
		while (tetri[i][j] && tetri[i][j] != '#')
			j++;
		while (tetri[i][j++])
			if (j - 1 < xstart && tetri[i][j - 1] == '#')
				xstart = j - 1;
	}
	if (!(piece->hash = (t_hash *)malloc(sizeof(t_hash))))
		return (0);
	if (!(piece->hash = save_tetri(tetri, letter, xstart, ystart)))
		return (0);
	return (1);
}

void		delete_pieces(t_tetri *pieces)
{
	t_hash *hashs;

	while (pieces->hash)
	{
		hashs = pieces->hash;
		free(pieces->hash);
		pieces->hash = hashs->next;
	}
	free(hashs);
	if (pieces->next->hash)
		delete_pieces(pieces->next);
	free(pieces);
}
