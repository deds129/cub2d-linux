#include "./includes/cub.h"

void ft_init_player(t_mapinfo *mapinfo, t_plr *plr)
{
	t_point point;

	ft_bzero(&point, sizeof(t_point));
	while (mapinfo->map[point.y])
	{
		point.x = 0;
		while (mapinfo->map[point.y][point.x])
		{
			if(ft_strchr("NEWS",mapinfo->map[point.y][point.x]))
			{
				plr->y = (point.y) * SCALE;
				plr->x = (point.x) * SCALE;

			}
			point.x++;
		}
		point.y++;
	}
}

void ft_print_player(t_all *all)
{
	t_point end;

	end.x = all->plr->x + SCALE;
	end.y = all->plr->y + SCALE;
	while(all->plr->y < end.y)
	{
		while (all->plr->x < end.x)
			mlx_pixel_put(all->wnd->mlx,all->wnd->win,all->plr->x++,all->plr->y,
				 0x119911);
		all->plr->x -= SCALE;
		all->plr->y++;
	}
}

