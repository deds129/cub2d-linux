#include "./includes/cub.h"

int             ft_key_press(int key, t_all *all)
{
	printf("key press: %p\n",all->wnd->win);
	printf("key: %d\n", key);
	if(key == 65307)
	{
		mlx_destroy_window(all->wnd->mlx, all->wnd->win);
		exit(0);
	}
	ft_draw_map(all);
	return (0);
}

//int ft_key_press(int key, t_all *all)
//{
//	printf("key_press");
//	mlx_clear_window(all->wnd->mlx,all->wnd->mlx);
//
//	if(key == 13)
//	{
//		printf("key_press");
//	}
//	if(key == 13)
//	{
//		all->plr->y += sin(all->plr->dir) * 4;
//		all->plr->x += cos(all->plr->dir) * 4;
//	}
//	if(key == 1)
//	{
//		all->plr->y -= sin(all->plr->dir) * 4;
//		all->plr->x -= cos(all->plr->dir) * 4;
//	}
//	if (key == 0)
//		all->plr->dir -= 0.1;
//	if (key == 2)
//		all->plr->dir += 0.1;
//	if (key == 53)
//		exit(0);
//	ft_draw_map(all);
//	return (0);
//}
