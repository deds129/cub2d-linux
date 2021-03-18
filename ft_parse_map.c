#include "./includes/cub.h"
int ft_row_counter(char **data)
{
	int i;
	int line_count;

	i = 0;
	line_count = 0;

	while (data[++i])
	{
		if (data[i][0] == ' ' ||  data[i][0] == '1' )
		{
			line_count++;
		}
	}
	return (line_count);
}

int ft_longest_line(char **data)
{
	int i;
	int max;

	max = 0;
	i = -1;
	while(data[++i])
	{
		if (data[i][0] == ' ' ||  data[i][0] == '1' && data[i])
		{
			if (ft_strlen(data[i]) > max)
				max = ft_strlen(data[i]);
		}
	}
	return (max);
}

//todo: дополнить каждую строку пробелами для проверки по строкам и столбцам
//пробросить ошибки, проверить валидность карты
void ft_parse_map(char **data, t_mapinfo *mapinfo)
{
	int i;
	int j;

	i = -1;
	if(!(mapinfo->map = (char **)malloc(sizeof(char) * (ft_longest_line(data)
			+ 1) *
			ft_row_counter(data))))
		ft_error(ERR_MALLOC);
	j = 0;
	while (data[++i])
	{
		if (data[i][0] == ' ' ||  data[i][0] == '1')
			mapinfo->map[j++] = data[i];
	}

}