#include "./includes/cub.h"

int	ft_close(int code, t_all *all)
{
	printf("X");
	return (0);
}

int             ft_key_press(int key, t_all *all)
{
	printf("key: %d\n", key);
	printf("win pointer ft_key_press: %p\n", all->wnd->win);
	printf("win mlx ft_key_press: %p\n", all->wnd->mlx);
	printf("win img ft_key_press: %p\n", all->wnd->img);


	if(key == 65307)
	{
		printf("esc\n");
		//mlx_destroy_window(all->wnd->mlx, all->wnd->win);
		exit(0);
	}
	if (key == 119)
	{
		all->plr->y -= 1;
	}
	if (key == 115)
	{
		all->plr->y += 1;
	}
	if (key == 97)
	{
		all->plr->x -= 1;
	}
	if (key == 100)
	{
		all->plr->x += 1;
	}

	printf("y: %f\n", all->plr->y);
	printf("x: %f\n", all->plr->x);
	mlx_clear_window(all->wnd->mlx, all->wnd->win);
	ft_draw_map(all);


	return (0);
}


