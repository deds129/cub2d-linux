#include "./includes/cub.h"
void	ft_draw_ray(t_all *all)
{
	t_plr	ray;
	int i;

	ray = *all->plr; // задаем координаты луча равные координатам
	ray.start = all->plr->dir - M_PI_4;
	ray.end = all->plr->dir + M_PI_4;
	printf("start : %f\n", ray.start);
	printf("end : %f\n", ray.end);


	while (ray.start < ray.end)
	{
		ray.x = all->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = all->plr->y;
		i = 0;
		while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		{
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
			pixel_put(all->wnd, ray.x, ray.y, 0x990099);
		}
		//field of view
		ray.start += (M_PI_2) / 512;
	}
}

void ft_set_dir(t_mapinfo *mapinfo, t_plr *plr)
{
	t_point point;

	ft_bzero(&point, sizeof(t_point));
	while (mapinfo->map[point.y])
	{
		point.x = 0;
		while (mapinfo->map[point.y][point.x])
		{
			if(ft_strchr("N",mapinfo->map[point.y][point.x]))
				plr->dir = M_PI_2;
			if(ft_strchr("E",mapinfo->map[point.y][point.x]))
				plr->dir = 0;
			if(ft_strchr("S",mapinfo->map[point.y][point.x]))
				plr->dir = 3 * M_PI_2;
			if(ft_strchr("W",mapinfo->map[point.y][point.x]))
				plr->dir = M_PI;
			point.x++;
		}
		point.y++;
	}
}

void ft_init_player(t_mapinfo *mapinfo, t_plr *plr)
{
	t_point point;
	int plr_flag;

	ft_bzero(&point, sizeof(t_point));
	plr_flag = 0;
	while (mapinfo->map[point.y])
	{
		point.x = 0;
		while (mapinfo->map[point.y][point.x])
		{
			if(ft_strchr("NEWS",mapinfo->map[point.y][point.x]))
			{
				ft_set_dir(mapinfo, plr);
				plr->y = (point.y) * SCALE;
				plr->x = (point.x) * SCALE;
				plr_flag++;
			}
			point.x++;
		}
		point.y++;
	}
	printf("players on map: %d\n", plr_flag);
	if (plr_flag != 1)
		ft_error(ERR_MAP_VALIDITY);
}

void ft_print_player(t_all *all)
{
	t_point end;

	end.x = all->plr->x + SCALE;
	end.y = all->plr->y + SCALE;
	all->plr->x * SCALE;
	all->plr->y * SCALE;
	while(all->plr->y < end.y)
	{
		while (all->plr->x < end.x)
		{
//			mlx_pixel_put(all->wnd->mlx, all->wnd->win, all->plr->x++,
//				 all->plr->y,0x2199F0);
			pixel_put(all->wnd,all->plr->x++,all->plr->y,0x2199F0);
		}
		all->plr->x -= SCALE;
		all->plr->y++;
	}
	all->plr->y -= SCALE;
}

