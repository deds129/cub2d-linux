#include "./includes/cub.h"

void	ft_view_conf(t_all *all)
{
	t_plr	ray;
	float len;
	ray = *all->plr; // задаем координаты луча равные координатам
	ray.start = all->plr->dir - M_PI_4;
	ray.end = all->plr->dir + M_PI_4;
	while (ray.start < ray.end)
	{
		ray.x = all->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = all->plr->y;
		len = 0;
		while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		{
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
			len++;
			pixel_put(all->wnd, ray.x, ray.y, 0x990099);
		}
		printf("ray len: %f\n", len);
		//todo: обработка каждого луча- рисуем столбец по лучу по gbritann
		ray.start += (M_PI_2) / all->wnd->width;
	}
}




int ft_frame_render(t_all *all)
{
	//pixel_put(all->wnd,all->plr->x,all->plr->y,0x2199F0);
	ft_view_conf(all);
	mlx_put_image_to_window(all->wnd->mlx, all->wnd->win,all->wnd->img,0,0);
	return (0);
}





//void ft_draw_map(t_all *all)
//{
//	t_point point;
//	ft_bzero(&point, sizeof(t_point));
//
//	while (all->map[point.y])
//	{
//		point.x = 0;
//		while (all->map[point.y][point.x])
//		{
//			ft_scale_img(point, all->wnd,0x000000);
//			if(all->map[point.y][point.x] == '1')
//			{
//				ft_scale_img(point, all->wnd,0xFFFFFF);
//			}
//			if(all->map[point.y][point.x] == '2')
//			{
//				ft_scale_img(point, all->wnd,0xFF0000);
//			}
//			point.x++;
//		}
//		point.y++;
//	}
//
//	//ft_print_player(all);
//	ft_draw_ray(all);
//}

