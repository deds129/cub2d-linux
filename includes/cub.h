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
# define ERR_ARGC_MAX -3
# define ERR_ARG_SAVE -4

# define ERR_FILENAME -11
# define ERR_FILE_OPEN -12

# define ERR_MAP_READ -111
# define ERR_MAP_VALIDITY -112
# define ERR_MAP_RES -113
# define ERR_MAP_BAD_ARG -114
# define ERR_MAP_T -115
# define ERR_MAP_BAD -116
# define ERR_MAP_C -117
# define ERR_MAP_OPEN -118

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
	char *no_texture;
	char *so_texture;
	char *we_texture;
	char *ea_texture;
	char *s_texture;

	int f_color_r;
	int f_color_g;
	int f_color_b;

	int c_color_r;
	int c_color_g;
	int c_color_b;
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
int ft_check_main_args(int argc, char *argv[]);

/*errors handle*/
void ft_error(int err_code);

/*read .cub*/
char **ft_read_cub(char *argv);

/*parse utils*/
int ft_valid_str(char *data);
int ft_count_lines(char **temp);
int ft_check_digit(char *line);
char *ft_chrrep(char *str,char chr, char new);
/*parse file -> add to struct params + errors*/
void ft_parse_cub(char **data, t_mapinfo *mapinfo);
void ft_parse_map(char **data, t_mapinfo *mapinfo);

/*player*/
void ft_init_player(char **map, t_plr *plr);

/*testing*/
void ft_print_params(t_mapinfo *mapinfo);


#endif
