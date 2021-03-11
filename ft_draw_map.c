#include "./includes/cub.h"
void ft_scale_img(t_point point, t_win *mwin)
{
	t_point end;

	end.x = (point.x + 1) *SCALE;
	end.y = (point.y + 1) *SCALE;
	point.x *= SCALE;
	point.y *= SCALE;
	while (point.y < end.y)
	{
		while (point.x < end.x)
			mlx_pixel_put(mwin->mlx,mwin->win,point.x++,point.y,0xFFFFFF);
		point.x -= SCALE;
		point.y++;
	}
}

void ft_draw_map(t_all *all)
{
	t_point point;
	printf("%p\n",all->wnd->win);
	ft_bzero(&point, sizeof(t_point));
	while (all->map[point.y])
	{
		point.x = 0;
		while (all->map[point.y][point.x])
		{
			if(all->map[point.y][point.x] == '1')
			{
				ft_scale_img(point, all->wnd);
			}
			point.x++;
		}
		point.y++;
	}
	ft_print_player(all);
	//mlx_put_image_to_window(all->wnd->mlx, all->wnd->win,all->wnd->img,0,0);
	//mlx_destroy_image(all->wnd->mlx, all->wnd->img);
}

