#ifndef CUB_H
# define CUB_H

# include "get_next_line.h"
//for MacOS
//# include "../minilib/mlx.h"
//for linux
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>

#define SCALE 16 // условный размер каждого квадратика в карте

# define ERR_MALLOC -1
# define ERR_ARGC_MIN -2
# define ERR_ARGC_MAX -5
# define ERR_FILENAME -3
# define ERR_ARG_SAVE -4
# define ERR_READ_MAP -6
# define ERR_MAP_VALIDITY -7
# define ERR_MAP_RES -8
# define ERR_MAP_BAD_ARG -9
# define ERR_MAP_T -10
# define ERR_BAD_MAP -11
# define ERR_MAP_C -12
# define ERR_MAP_OPEN -13

//# define W 13
//# define S 1
//# define A 0
//# define D 2
//# define LEFT 123
//# define RIGHT 124
//# define ESC 53

typedef struct	s_mapinfo
{
	int res_x;
	int res_y;
	char *north_texture;
	char *south_texture;
	char *west_texture;
	char *east_texture;
	char *sprite_texture;

	int floor_color_r;
	int floor_color_g;
	int floor_color_b;

	int celling_color_r;
	int celling_color_g;
	int celling_color_b;
	char **map;

}				t_mapinfo;

typedef struct	s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
}				  t_win;

typedef struct	s_point // структура для квадратика/точки
{
	int			x;
	int			y;
}				  t_point;

typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start; //угол?
	float		end; //угол
}				  t_plr;

typedef struct	s_all // структура для всего вместе
{
	t_win		*wnd;
	t_plr		*plr;
	char		**map;
}				  t_all;

/*args parse*/
int ft_parse_args(int ac, char *filename, char *save);

/*errors handle*/
void ft_error(int err_code);

#endif
