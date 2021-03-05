#include "./includes/cub.h"

//todo: точка входа
int	main(int argc, char *argv[])
{
	t_mapinfo mapinfo;

	if(argc == 1)
		ft_error(ERR_ARGC_MIN);
	else if (argc == 2)
	{
		printf("filename: %s\n", argv[1]);
		if (ft_parse_args(2, argv[1], NULL))
		{
			//init_structs
			//parse_dot_cub

		}
	}
	else if (argc == 3)
		{
			printf("filename: %s\n", argv[1]);
			printf("--save\n");
			ft_parse_args(3, argv[1], argv[2]);
		}
	else
		ft_error(ERR_ARGC_MAX);


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