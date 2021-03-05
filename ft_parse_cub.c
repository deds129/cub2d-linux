#include "./includes/cub.h"

//todo: remove this
void ft_print_params(t_mapinfo *mapinfo)
{
	int i;
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
	//построчно выводим 2м массив

//	printf("\n===MAP===\n");
//	i = -1;
//	while(mapinfo->map[++i])
//		printf("%s\n",mapinfo->map[i]);

}

int ft_count_lines(char **temp)
{
	int i;

	//todo: check null-case
	i = 0;
	while (temp[i])
		i++;
	return (i);
}

int ft_check_digit(char *line)
{
	int i;

	//todo: check null-case
	i = -1;
	while (line[++i])
	{
		if(!(ft_isdigit(line[i])))
			return (0);
	}
	return (1);
}

//fix & change this function
//idea replace commas to space and use split & check + errors
void ft_set_color(char *str, t_mapinfo *mapinfo, char flag)
{
	int i;

	i = 1;
	if(flag == 'f')
	{
		while (str[i] && (str[i] == ' ' || str[i] == ','))
			i++;
		mapinfo->f_color_r = ft_atoi(&(*(str + i)));

		while (str[i] && ft_isdigit(str[i]))
			i++;
		while (str[i] && (str[i] == ' ' || str[i] == ','))
			i++;
		mapinfo->f_color_g = ft_atoi(&(*(str + i)));

		while (str[i] && ft_isdigit(str[i]))
			i++;
		while (str[i] && (str[i] == ' ' || str[i] == ','))
			i++;
		mapinfo->f_color_b = ft_atoi(&(*(str + i)));
	}
	if(flag == 'c')
	{
		while (str[i] && (str[i] == ' ' || str[i] == ','))
			i++;
		mapinfo->c_color_r = ft_atoi(&(*(str + i)));

		while (str[i] && ft_isdigit(str[i]))
			i++;
		while (str[i] && (str[i] == ' ' || str[i] == ','))
			i++;
		mapinfo->c_color_g = ft_atoi(&(*(str + i)));

		while (str[i] && ft_isdigit(str[i]))
			i++;
		while (str[i] && (str[i] == ' ' || str[i] == ','))
			i++;
		mapinfo->c_color_b = ft_atoi(&(*(str + i)));
	}
}

void ft_set_resolution(char *str, t_mapinfo *mapinfo)
{
	char **tmp;
	int i;

	i = 0;
	tmp = NULL;
	if (!(tmp = ft_split(str, ' ')))
		ft_error(ERR_MALLOC);
	if (ft_count_lines(tmp) == 3 || ft_check_digit(tmp[i]) ||
	ft_check_digit(tmp[i]))
	{
		mapinfo->res_x = ft_atoi(tmp[1]);
		mapinfo->res_y = ft_atoi(tmp[2]);
	}
	else
		ft_error(ERR_MAP_RES);
}


void ft_parse_cub(char **data, t_mapinfo *mapinfo) //int map_size
{
	int i;

	i = 0;
	while (data[i])
	{
		if (data[i][0] == 'R' && data[i][1] == ' ')
			ft_set_resolution(data[i], mapinfo);
		//check to printable letters
		else if (data[i][0] == 'N' && data[i][1] == 'O')
			mapinfo->no_texture = ft_strtrim(&data[i][2]," ");
		else if (data[i][0] == 'S' && data[i][1] == 'O')
			mapinfo->so_texture = ft_strtrim(&data[i][2]," ");
		else if (data[i][0] == 'W' && data[i][1] == 'E')
			mapinfo->we_texture = ft_strtrim(&data[i][2]," ");
		else if (data[i][0] == 'E' && data[i][1] == 'A')
			mapinfo->ea_texture = ft_strtrim(&data[i][2]," ");
		else if (data[i][0] == 'S' && data[i][1] == ' ')
			mapinfo->s_texture = ft_strtrim(&data[i][1]," ");
		//fix this
		else if (data[i][0] == 'F' && data[i][1] == ' ')
			ft_set_color(data[i],mapinfo,'f');
		else if (data[i][0] == 'C' && data[i][1] == ' ')
			ft_set_color(data[i], mapinfo,'c');

		i++;
	}
	ft_print_params(mapinfo);
}
