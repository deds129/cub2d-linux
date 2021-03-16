#include "./includes/cub.h"

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


