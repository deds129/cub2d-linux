#include "./includes/cub.h"




void ft_parse_cub(char **data, t_mapinfo *mapinfo) //int map_size
{
	int i;

	i = 0;
	while (data[i])
	{
		if (data[i][0] == 'R' && data[i][1] == ' ')
			ft_set_resolution(data[i], mapinfo);
		else if (data[i][0] == 'N' && data[i][1] == 'O')
			mapinfo->north_texture = ft_strtrim(&data[i][2]," ");
		else if (data[i][0] == 'S' && data[i][1] == 'O')
			mapinfo->south_texture = ft_strtrim(&data[i][2]," ");
		else if (data[i][0] == 'W' && data[i][1] == 'E')
			mapinfo->west_texture = ft_strtrim(&data[i][2]," ");
		else if (data[i][0] == 'E' && data[i][1] == 'A')
			mapinfo->east_texture = ft_strtrim(&data[i][2]," ");
		else if (data[i][0] == 'S' && data[i][1] == ' ')
			mapinfo->sprite_texture = ft_strtrim(&data[i][1]," ");

		else if (data[i][0] == 'F' && data[i][1] == ' ')
			ft_set_color(data[i],mapinfo,'f');
		else if (data[i][0] == 'C' && data[i][1] == ' ')
			ft_set_color(data[i], mapinfo,'c');

		i++;
	}
}