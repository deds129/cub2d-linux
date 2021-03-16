#include "./includes/cub.h"

void ft_init_window(t_win *win, t_mapinfo *mapinfo, char *wname)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, mapinfo->res_y, mapinfo->res_x, wname);
	win->img = mlx_new_image(win->mlx,mapinfo->res_y, mapinfo->res_x);
	win->addr = mlx_get_data_addr(win->img, &win->bpp,&win->line_l, &win->en);
	win->width = mapinfo->res_x;
	win->height = mapinfo->res_y;
}

