#include "./includes/cub.h"

//todo: remove this
void ft_print_params(t_mapinfo *mapinfo)
{
	printf("=====================\n");
	printf("res_x: %d\n",mapinfo->res_x);
	printf("res_y: %d\n",mapinfo->res_y);
	printf("no_texture: %s\n",mapinfo->no_texture);
	printf("so_texture: %s\n",mapinfo->so_texture);
	printf("we_texture: %s\n",mapinfo->we_texture);
	printf("ea_texture: %s\n",mapinfo->ea_texture);
	printf("s_texture: %s\n",mapinfo->s_texture);
	printf("floor_color_r: %i\n",mapinfo->f_color_r);
	printf("floor_color_g: %i\n",mapinfo->f_color_g);
	printf("floor_color_b: %i\n",mapinfo->f_color_b);
	printf("celling_color_r: %i\n",mapinfo->c_color_r);
	printf("celling_color_g: %i\n",mapinfo->c_color_g);
	printf("celling_color_b: %i\n",mapinfo->c_color_b);
	printf("\n===MAP===\n");
	int i;
	i = -1;
	while(mapinfo->map[++i])
		printf("%s\n",mapinfo->map[i]);

}

//fix & change this function
//idea replace commas to space and use split & check + errors
void ft_set_color(char *str, t_mapinfo *mapinfo, char flag)
{
	char **tmp;
	int i;
	char *new_str;
	i = 0;
	tmp = NULL;
	new_str = NULL;
	if (!(new_str = ft_chrrep(str,',',' ')))
		ft_error(ERR_MALLOC);
	 //printf("%s\n", new_str);
	if (!(tmp = ft_split(new_str, ' ')))
		ft_error(ERR_MALLOC);
//	int j = 0;
//	while (tmp[j])
//	{
//		ft_putendl_fd(tmp[j],2);
//		j++;
//	}
	if (ft_count_lines(tmp) == 4 && ft_check_digit(tmp[1]) &&
		ft_check_digit(tmp[2]) && ft_check_digit(tmp[3]))
	{
		if (flag == 'F')
		{
			mapinfo->f_color_r = ft_atoi(tmp[1]);
			mapinfo->f_color_g = ft_atoi(tmp[2]);
			mapinfo->f_color_b = ft_atoi(tmp[3]);
		}
		else if (flag == 'C')
		{
			mapinfo->c_color_r = ft_atoi(tmp[1]);
			mapinfo->c_color_g = ft_atoi(tmp[2]);
			mapinfo->c_color_b = ft_atoi(tmp[3]);
		}
	}
	else
		ft_error(ERR_MAP_C);
	free(tmp);
	free(new_str);
}

void ft_set_resolution(char *str, t_mapinfo *mapinfo)
{
	char **tmp;
	int i;

	i = 0;
	tmp = NULL;
	if (!(tmp = ft_split(str, ' ')))
		ft_error(ERR_MALLOC);
	if (ft_count_lines(tmp) == 3 &&  ft_check_digit(tmp[1]) &&
			ft_check_digit(tmp[2]) )
	{
		mapinfo->res_x = ft_atoi(tmp[1]);
		mapinfo->res_y = ft_atoi(tmp[2]);
	}
	else
		ft_error(ERR_MAP_RES);
	free(tmp);
}

void ft_parse_cub(char **data, t_mapinfo *mapinfo) //int map_size
{
	int i;

	i = -1;
	while (data[++i])
	{
		//printf("%c\n",data[i][0]);
		if(ft_valid_str(data[i]) == 1)
		{
			//printf("test");
			if (data[i][0] == 'R' && data[i][1] == ' ')
				ft_set_resolution(data[i], mapinfo);
			else if (data[i][0] == 'N' && data[i][1] == 'O')
				mapinfo->no_texture = ft_strtrim(&data[i][2], " ");
			else if (data[i][0] == 'S' && data[i][1] == 'O')
				mapinfo->so_texture = ft_strtrim(&data[i][2], " ");
			else if (data[i][0] == 'W' && data[i][1] == 'E')
				mapinfo->we_texture = ft_strtrim(&data[i][2], " ");
			else if (data[i][0] == 'E' && data[i][1] == 'A')
				mapinfo->ea_texture = ft_strtrim(&data[i][2], " ");
			else if (data[i][0] == 'S' && data[i][1] == ' ')
				mapinfo->s_texture = ft_strtrim(&data[i][1], " ");
			else if (data[i][0] == 'F' && data[i][1] == ' ')
				ft_set_color(data[i], mapinfo, 'F');
			else if (data[i][0] == 'C' && data[i][1] == ' ')
				ft_set_color(data[i], mapinfo, 'C');
		}
		else
			ft_error(ERR_MAP_VALIDITY);
	}

}
