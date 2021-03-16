#include "./includes/cub.h"

int ft_valid_str(char *data)
{
	if (data[0] == 'R' || data[0] == 'N' || data[0] == 'S' ||
		data[0] == 'W' || data[0] == 'E' || data[0] == 'F' ||
		data[0] == 'C' || data[0] == '\n' || data[0] == ' ' ||
		data[0] == '1' || data[0] == '\0')
		return (1);
	return (0);
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
//return new string with replaced char to new char
//malloc problem
char *ft_chrrep(char *str,char chr, char new)
{
	int i;
	i = 0;
	char *tmp;
	tmp = ft_strdup(str);
	while(tmp[i])
	{
		if(tmp[i] == chr)
		{
			tmp[i] = new;
		}
		i++;
	}
	return (tmp);
}