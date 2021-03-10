#include "./includes/cub.h"


void ft_init_game(t_mapinfo *mapinfo, t_all *all, char *name)
{
	t_win win;
	t_plr plr;

	ft_init_player(mapinfo,&plr);
	ft_init_window(&win,mapinfo,name);
	all->wnd = &win;
	all->plr = &plr;
	all->map = mapinfo->map;
//	printf("init func\n");
//	printf("%p\n",win.win);
//	printf("%p\n",all->wnd->win);

	ft_draw_map(all);
	ft_print_player(all);
}




