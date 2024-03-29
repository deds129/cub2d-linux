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

//LINUX
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

//MAC OS
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
	int			height;
	int			width;
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
char *ft_chrrep(char *str,char chr, char new_chr);

/*parse file -> add to struct params + errors*/
void ft_parse_cub(char **data, t_mapinfo *mapinfo);
void ft_parse_map(char **data, t_mapinfo *mapinfo);

/*init all + linking*/
void ft_init(t_mapinfo *mapinfo, t_all *all, char *name);
void ft_init_player(t_mapinfo *mapinfo, t_plr *plr);
void ft_init_window(t_win *win, t_mapinfo *mapinfo, char *wname);

/*drawing*/
void	pixel_put(t_win *twin, int x, int y, int color);
int 	ft_frame_render(t_all *all);

void ft_draw_map(t_all *all);
void ft_print_player(t_all *all);
void	ft_draw_ray(t_all *all);

/*testing*/
void ft_print_params(t_mapinfo *mapinfo);
void ft_init_game(t_mapinfo *mapinfo, t_all *all, char *name);

/*hooks, key press*/
int             ft_key_press(int keycode, t_all *all);
int				ft_close(int code, t_all *all);

#endif
