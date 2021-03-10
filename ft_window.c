#include "./includes/cub.h"

void ft_init_window(t_win *win, t_mapinfo *mapinfo, char *wname)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, mapinfo->res_y, mapinfo->res_x,
							  wname);
}

