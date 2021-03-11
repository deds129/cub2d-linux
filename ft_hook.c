#include "./includes/cub.h"

int	ft_close(int code, t_all *all)
{
	printf("X");
	return (0);
}

int             ft_key_press(int key, t_all *all)
{
	//printf("key press: %p\n",&all->wnd->win);
	printf("key: %d\n", key);
	mlx_clear_window(all->wnd->mlx, all ->wnd->win);
	if(key == 65307)
	{
		printf("esc\n");
		mlx_destroy_window(all->wnd->mlx, all->wnd->win);
		exit(0);
	}
	if (key == 119)
	{
		all->plr->y -= 1;
		printf("w\n");
	}
	if (key == 115)
	{
		all->plr->y += 1;
		printf("s\n");
	}
	if (key == 97)
	{
		all->plr->x -= 1;
		printf("a\n");
	}
	if (key == 100)
	{
		all->plr->x += 1;
		printf("d\n");
	}

	printf("y: %f\n", all->plr->y);
	printf("x: %f\n", all->plr->x);
	ft_draw_map(all);
	return (0);
}


