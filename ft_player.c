#include "./includes/cub.h"

void ft_init_player(t_mapinfo *mapinfo, t_plr *plr)
{
	t_point point;

	ft_bzero(&point, sizeof(t_point));
	while (mapinfo->map[point.y])
	{
		//printf("%s\n",map[point.y]);
		point.x = 0;
		while (mapinfo->map[point.y][point.x])
		{
			if(ft_strchr("NEWS",mapinfo->map[point.y][point.x]))
			{
//				plr->y = (point.y) * SCALE;
//				plr->x = (point.x) * SCALE;
				plr->y = (point.y);
				plr->x = (point.x);
			}
			point.x++;
		}
		point.y++;
	}
}

