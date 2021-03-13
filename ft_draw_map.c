#include "./includes/cub.h"
void ft_scale_img(t_point point, t_win *wnd, long color)
{
	t_point end;

	end.x = (point.x + 1) *SCALE;
	end.y = (point.y + 1) *SCALE;
	point.x *= SCALE;
	point.y *= SCALE;
	while (point.y < end.y)
	{
		while (point.x < end.x)
		{
			pixel_put(wnd,point.x++,point.y,color);
			//mlx_pixel_put(wnd->mlx,wnd->win,point.x++,point.y,0xFFFFFF);
		}
		point.x -= SCALE;
		point.y++;
	}

}

void ft_draw_map(t_all *all)
{
	t_point point;
	printf("win pointer ft_draw_map: %p\n", all->wnd->win);
	printf("win mlx ft_draw_map: %p\n", all->wnd->mlx);
	printf("win img ft_draw_map: %p\n", all->wnd->img);
	ft_bzero(&point, sizeof(t_point));
	mlx_put_image_to_window(all->wnd->mlx, all->wnd->win,all->wnd->img,0,0);


	while (all->map[point.y])
	{
		point.x = 0;
		while (all->map[point.y][point.x])
		{
			ft_scale_img(point, all->wnd,0x000000);
			if(all->map[point.y][point.x] == '1')
			{
				ft_scale_img(point, all->wnd,0xFFFFFF);
			}
			if(all->map[point.y][point.x] == '2')
			{
				ft_scale_img(point, all->wnd,0xFF0000);
			}
			point.x++;
		}
		point.y++;
	}
	ft_print_player(all);
}

