#include "./includes/cub.h"

int				ft_close(int code, t_all *all)
{
	exit(0);
}

int             ft_key_press(int key, t_all *all)
{
	printf("\nkey: %d\n", key);

	if(key == ESC)
	{
		printf("esc\n");
		//mlx_destroy_window(all->wnd->mlx, all->wnd->win);
		exit(0);
	}
	if (key == W)
	{
		all->plr->y += sin(all->plr->dir) * 2;
		all->plr->x += cos(all->plr->dir) * 2;
	}
	if (key == S)
	{
		all->plr->y -= sin(all->plr->dir) * 2;
		all->plr->x -= cos(all->plr->dir) * 2;
	}
	//todo: make strave
//	if (key == A)
//	{
//		all->plr->y += sin(all->plr->dir) * 2;
//		all->plr->x -= cos(all->plr->dir) * 2;
//	}
//
//	if (key == D)
//	{
//		all->plr->y -= sin(all->plr->dir) * 2;
//		all->plr->x += cos(all->plr->dir) * 2;
//	}

	if (key == LEFT)
		all->plr->dir -= tan(0.1);
	if (key == RIGHT)
		all->plr->dir += tan(0.1);

	printf("dir : %f\n", all->plr->dir);
	printf("y: %f\n", all->plr->y);
	printf("x: %f\n", all->plr->x);
	mlx_clear_window(all->wnd->mlx, all->wnd->win);
	ft_frame_render(all);
	return (0);
}


