#include "./includes/cub.h"
void            pixel_put(t_win *wnd, int x, int y, int color)
{
	char    *dst;

	dst = wnd->addr + (y * wnd->line_l + x * (wnd->bpp / 8));
	*(unsigned int*)dst = color;
}



int ft_check_main_args(int argc, char *argv[])
{
	if(argc == 1)
	{
		ft_error(ERR_ARGC_MIN);
		return (0);
	}
	else if (argc == 2)
	{
		//printf("filename: %s\n", argv[1]);
		ft_parse_args(2, argv[1], NULL);
		return (1);
	}
	else if (argc == 3)
	{
		//printf("filename: %s\n", argv[1]);
		//printf("--save\n");
		ft_parse_args(3, argv[1], argv[2]);
		return (2);
	}
	else
	{
		ft_error(ERR_ARGC_MAX);
		return (0);
	}
}

//todo: точка входа
int	main(int argc, char *argv[])
{
	t_mapinfo mapinfo;
	t_all all;
	t_win win;
	t_plr plr;

	char **data;
	ft_bzero(&all,sizeof(all));
	//args error handle
	//return - 2 w/o save; return - 3 w/ save
	if (ft_check_main_args(argc, argv) == 0)
		return (1);
	ft_bzero(&mapinfo,sizeof(mapinfo));
	data = ft_read_cub((char *)argv[1]);

	//parse map params + valid check
	ft_parse_cub(data, &mapinfo);
	//parse map + valid check
	ft_parse_map(data, &mapinfo);
	//test func
	//ft_print_params(&mapinfo);

	//todo: init in new func
	//ft_init_game(&mapinfo,&all,argv[1]);
	ft_init_player(&mapinfo,&plr);
	ft_init_window(&win,&mapinfo,argv[1]);
//	printf("win pointer main: %p\n", win.win);
//	printf("win mlx main: %p\n", win.mlx);
//	printf("win img main: %p\n", win.img);
	all.wnd = &win;
	all.plr = &plr;
	all.map = mapinfo.map;




	printf("start y: %f\n", all.plr->y);
	printf("start x: %f\n", all.plr->x);
	ft_draw_map(&all);

	//key hooks read
	mlx_hook(all.wnd->win,2,(1L << 0), &ft_key_press, &all);
	//todo: fix close window
	mlx_hook(all.wnd->win, 17, (1L << 0), &ft_close, &all);
	mlx_loop(all.wnd->mlx);
	//todo: создать отдельный блок для отчистки после выполнения программы
	free(mapinfo.map);
	free(data);
	return (0);
}
