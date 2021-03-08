#include "./includes/cub.h"

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

void ft_init(t_mapinfo *mapinfo, t_all *all, char *name)
{
	t_win win;
	t_plr plr;

	ft_init_player(mapinfo,&plr);
	printf("Player position: y = %f | x = %f" , plr.y ,plr.x);
	ft_init_window(&win,mapinfo,name);
	all->wnd = &win;
	all->plr = &plr;
}

//todo: точка входа
int	main(int argc, char *argv[])
{
	t_mapinfo mapinfo;
	t_all all;

	char **data;

	//args error handle
	//return - 2 w/o save; return - 3 w/ save
	if (ft_check_main_args(argc, argv) == 0)
		return (1);

	//init params
	ft_bzero(&mapinfo,sizeof(mapinfo));

	//read file to 2nd array
	data = ft_read_cub((char *)argv[1]);
//	int i = -1;
//	while (data[++i])
//		ft_putendl_fd(data[i],1);


	//parse map params + valid check
	ft_parse_cub(data, &mapinfo);
	//parse map + valid check
	ft_parse_map(data, &mapinfo);
	//test func
	//ft_print_params(&mapinfo);
	//init player pos + init window
	ft_init(&mapinfo,&all,argv[1]);

	mlx_loop(all.wnd->mlx);
	//todo: создать отдельный блок для отчистки после выполнения программы
	free(mapinfo.map);
	free(data);
	return (0);
}





//t_all all;
//t_win win;
//t_plr plr;
//
//ft_parse_cub((char *)argv[1], &mapinfo);
//
//
//all.map = mapinfo.map;
//
//ft_init_player(mapinfo.map,&plr);
//printf("Player position: y = %f | x = %f" , plr.y ,plr.x);
//
//win.mlx = mlx_init();
//win.win = mlx_new_window(win.mlx, mapinfo.res_y, mapinfo.res_x,"cubic");
//win.img = mlx_new_image(win.mlx,mapinfo.res_y, mapinfo.res_x);
//win.addr = mlx_get_data_addr(win.img, &win.bpp,&win.line_l, &win.en);
//all.plr = &plr;
//all.wnd = &win;
//ft_draw_screen(&all);
//mlx_hook(win.win,2,(1L << 0), &ft_key_press, &all);
//void ft_init_player(char **map, t_plr *plr)
//{
//	t_point point;
//
//	ft_bzero(&point, sizeof(t_point));
//	while (map[point.y])
//	{
//		point.x = 0;
//		while (map[point.y][point.x])
//		{
//			if(ft_strchr("NEWS",map[point.y][point.x]))
//			{
//				plr->y = (point.y) * SCALE;
//				plr->x = (point.x) * SCALE;
//			}
//			point.x++;
//		}
//		point.y++;
//	}
//}