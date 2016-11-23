/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:14:47 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/23 15:04:36 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

# include <stdio.h>

# define BUFF_SIZE 21

typedef	struct	s_hash
{
	int				x;
	int				y;
	char			letter;
	struct s_hash	*next;
}				t_hash;

typedef struct	s_tetri
{
	struct s_hash	*hash;
	struct s_tetri	*next;
}				t_tetri;

t_tetri			*get_pieces(int fd, t_tetri *pieces, char *buff, int *nbpieces);
int				tetri_isvalid(char **tetri);
int				check_tetri(char *buff);
int				usageerror(void);
int				print_error(void);
t_hash			*save_hash(t_hash *hash, char letter, int i, int j);
void			init(int *i, int *j, int *k, int *l);
int				locate_tetri(t_tetri *piece, char letter, char **tetri);
t_hash			*save_tetri(char **tetri, char letter, int xstart, int ystart);
int				place_tetri(char **map, t_hash *hashs, int i, int j);
int				resolve(char **map, t_tetri *piece, int i, int j);
char			**generate_map(size_t size);
char			**ft_realloc_map(char **map, int new_size);
void			delete_map(char **map);
void			display_map(char **map);
void			delete_pieces(t_tetri *pieces);

#endif
