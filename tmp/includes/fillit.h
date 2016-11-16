#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

# define BUF_SIZE 21
# define ERROR ft_putstr("error\n")

typedef struct		s_map
{
	char	**map;
	size_t	size;
}					t_map;


typedef struct		s_point
{
	int	x;
	int	y;
}					t_point;

typedef struct		s_tetri
{
	t_point			point[3];
	char			id;
	int				placed;
	int				tested;
	struct s_tetri	*begin;
	struct s_tetri	*next;
}					t_tetri;


	t_tetri			*check_input(char *str);

	char			**generate_map(size_t size);
	void			delete_map(t_map *map);
	void			display_map(char **map);
	t_map			*add_map(size_t	size);
	char			**get_tetri_map(char *buf);

	t_tetri			*create_tetri(char **tetri_map, char id);
	t_tetri			*add_tetri(t_tetri *tetri, t_tetri *new_tetri);
	void			set_point(t_point *point, int x, int y);
	void			set_tetri(t_tetri *tetri, char id, int placed, int tested);
	void			delete_lst_tetri(t_tetri *tetri);
	void			delete_map_tetri(char **map);
	void			init_tetri_start(t_tetri *tetri);
	void			init_tetri_placed(t_tetri *tetri);
	size_t			ft_lstlen(t_tetri *tetri);

	int				is_solved(t_tetri *tetri);
	int				chk_pos(t_map *map, t_point coord, t_tetri *tetri, int nbr_point);
	int				is_placed(t_map *map, t_point coord, t_tetri *t, int nbr_t);
	int				place(t_map *map, t_point coord, t_tetri *t, int nbr_t);
	int				resolve(t_map *map, t_tetri *tetri);

	void			ft_putchar(char c);
	void			ft_putstr(const char *str);



#endif